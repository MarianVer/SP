#define _CRT_SECURE_NO_WARNINGS

#define ARRAY_INTERVAL 128

#define USE_REVERSE_ASSIGNMENT
#define USE_COMPARE_WITH_EQUAL

#define LA_IS  2
#define LA_NOT 4

// Підключаємо твій заголовочний файл з граматикою
#include "LexicaByRegExAndSyntaxByLL2protototype.h"

#define MAX_RULES 356
#define MAX_TOKEN_SIZE 128
#define MAX_RTOKEN_COUNT 16
#define MAX_RHSCONTEINER_COUNT 3
#define MAX_MARK_COUNT 16

typedef struct {
	char secondMarksType;
	char secondMarks[MAX_MARK_COUNT][MAX_TOKEN_SIZE];
	int rhs_count;
	char rhs[MAX_RTOKEN_COUNT][MAX_TOKEN_SIZE];
} RHSConteiner;

typedef struct {
	char lhs[MAX_TOKEN_SIZE];
	RHSConteiner rhss[MAX_RHSCONTEINER_COUNT];
} Rule;

typedef struct {
	char firstMarksType;
	char firstMarks[MAX_MARK_COUNT][MAX_TOKEN_SIZE];
	Rule rule;
} MarkedRule;

typedef struct {
	MarkedRule multiRules[MAX_RULES];
	char start_symbol[MAX_TOKEN_SIZE];
} Grammar;

Grammar grammar = {
	GRAMMAR_LL2__2025
};

// Forward declarations
struct LexemInfo;
bool getIndexAfterFragmentSyntax(char* ruleName, int& lexemIndex, struct LexemInfo* lexemInfoTable, Grammar* grammar, int depth);

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <regex>
#include "stdlib.h"
#include "string.h"

// Налаштування файлів для Варіанту 2
#define DEFAULT_INPUT_FILE "file1.v02"
#define AST_OUTPUT_FILE "ast.txt"

unsigned char errorMessagesPtrToLastBytePtr[8 * 1024 * 1024] = { '\0' };

#define SUCCESS_STATE 0
#define DEBUG_MODE 4096
#define RERUN_MODE
#define VALUE_SIZE 4
#define MAX_TEXT_SIZE 8192
#define MAX_WORD_COUNT (MAX_TEXT_SIZE / 5)
#define MAX_LEXEM_SIZE 1024
#define MAX_VARIABLES_COUNT 256
#define MAX_KEYWORD_COUNT 64

#define KEYWORD_LEXEME_TYPE 1
#define IDENTIFIER_LEXEME_TYPE 2 
#define VALUE_LEXEME_TYPE 4
#define UNEXPEXTED_LEXEME_TYPE 127

#ifndef LEXEM_INFO_
#define LEXEM_INFO_
struct NonContainedLexemInfo;
struct LexemInfo {
public:
	char lexemStr[MAX_LEXEM_SIZE];
	unsigned long long int lexemId;
	unsigned long long int tokenType;
	unsigned long long int ifvalue;
	unsigned long long int row;
	unsigned long long int col;

	LexemInfo();
	LexemInfo(const char* lexemStr, unsigned long long int lexemId, unsigned long long int tokenType, unsigned long long int ifvalue, unsigned long long int row, unsigned long long int col);
	LexemInfo(const NonContainedLexemInfo& nonContainedLexemInfo);
};
#endif

#ifndef NON_CONTAINED_LEXEM_INFO_
#define NON_CONTAINED_LEXEM_INFO_
struct LexemInfo;
struct NonContainedLexemInfo {
	char* lexemStr;
	unsigned long long int lexemId;
	unsigned long long int tokenType;
	unsigned long long int ifvalue;
	unsigned long long int row;
	unsigned long long int col;

	NonContainedLexemInfo();
	NonContainedLexemInfo(const LexemInfo& lexemInfo);
};
#endif

// Global vars
#define MAX_ACCESSORY_STACK_SIZE_123 128
char tempStrFor_123[MAX_TEXT_SIZE] = { '\0' };
unsigned long long int tempStrForCurrIndex = 0;
struct LexemInfo lexemesInfoTable[MAX_WORD_COUNT];
struct LexemInfo* lastLexemInfoInTable = lexemesInfoTable;
char identifierIdsTable[MAX_WORD_COUNT][MAX_LEXEM_SIZE] = { "" };

// Implementations of Structs
LexemInfo::LexemInfo() {
	lexemStr[0] = '\0'; lexemId = 0; tokenType = 0; ifvalue = 0; row = ~0; col = ~0;
}
LexemInfo::LexemInfo(const char* lexemStr, unsigned long long int lexemId, unsigned long long int tokenType, unsigned long long int ifvalue, unsigned long long int row, unsigned long long int col) {
	strncpy(this->lexemStr, lexemStr, MAX_LEXEM_SIZE);
	this->lexemId = lexemId; this->tokenType = tokenType; this->ifvalue = ifvalue; this->row = row; this->col = col;
}
LexemInfo::LexemInfo(const NonContainedLexemInfo& nonContainedLexemInfo) {
	strncpy(lexemStr, nonContainedLexemInfo.lexemStr, MAX_LEXEM_SIZE);
	lexemId = nonContainedLexemInfo.lexemId; tokenType = nonContainedLexemInfo.tokenType; ifvalue = nonContainedLexemInfo.ifvalue; row = nonContainedLexemInfo.row; col = nonContainedLexemInfo.col;
}
NonContainedLexemInfo::NonContainedLexemInfo() {
	(lexemStr = tempStrFor_123 + tempStrForCurrIndex)[0] = '\0';
	tempStrForCurrIndex += 32; lexemId = 0; tokenType = 0; ifvalue = 0; row = ~0; col = ~0;
}
NonContainedLexemInfo::NonContainedLexemInfo(const LexemInfo& lexemInfo) {
	lexemStr = (char*)lexemInfo.lexemStr;
	lexemId = lexemInfo.lexemId; tokenType = lexemInfo.tokenType; ifvalue = lexemInfo.ifvalue; row = lexemInfo.row; col = lexemInfo.col;
}

// Print functions
void printLexemes(struct LexemInfo* lexemInfoTable, char printBadLexeme) {
	if (printBadLexeme) printf("Bad lexeme:\r\n");
	else printf("Lexemes table:\r\n");
	printf("-------------------------------------------------------------------\r\n");
	printf("index           lexeme          id      type    ifvalue row     col\r\n");
	printf("-------------------------------------------------------------------\r\n");
	for (unsigned long long int index = 0; (!index || !printBadLexeme) && lexemInfoTable[index].lexemStr[0] != '\0'; ++index) {
		printf("%5llu%17s%12llu%10llu%11llu%4lld%8lld\r\n", index, lexemInfoTable[index].lexemStr, lexemInfoTable[index].lexemId, lexemInfoTable[index].tokenType, lexemInfoTable[index].ifvalue, lexemInfoTable[index].row, lexemInfoTable[index].col);
	}
	printf("-------------------------------------------------------------------\r\n\r\n");
}

unsigned int getIdentifierId(char(*identifierIdsTable)[MAX_LEXEM_SIZE], char* str) {
	unsigned int index = 0;
	for (; identifierIdsTable[index][0] != '\0'; ++index) {
		if (!strncmp(identifierIdsTable[index], str, MAX_LEXEM_SIZE)) return index;
	}
	strncpy(identifierIdsTable[index], str, MAX_LEXEM_SIZE);
	identifierIdsTable[index + 1][0] = '\0';
	return index;
}

// Lexical Analyzers
unsigned int tryToGetIdentifier(struct LexemInfo* lexemInfoInTable, char(*identifierIdsTable)[MAX_LEXEM_SIZE]) {
	char* identifiers_re = (char*)IDENTIFIERS_RE; 
	// Regex for Variant 2: _[A-Z][A-Z]
	if (std::regex_match(std::string(lexemInfoInTable->lexemStr), std::regex(identifiers_re))) {
		lexemInfoInTable->lexemId = getIdentifierId(identifierIdsTable, lexemInfoInTable->lexemStr);
		lexemInfoInTable->tokenType = IDENTIFIER_LEXEME_TYPE;
		return SUCCESS_STATE;
	}
	return ~SUCCESS_STATE;
}

unsigned int tryToGetUnsignedValue(struct LexemInfo* lexemInfoInTable) {
	char* unsignedvalues_re = (char*)UNSIGNEDVALUES_RE;
	if (std::regex_match(std::string(lexemInfoInTable->lexemStr), std::regex(unsignedvalues_re))) {
		lexemInfoInTable->ifvalue = atoi(lastLexemInfoInTable->lexemStr);
		lexemInfoInTable->lexemId = MAX_VARIABLES_COUNT + MAX_KEYWORD_COUNT;
		lexemInfoInTable->tokenType = VALUE_LEXEME_TYPE;
		return SUCCESS_STATE;
	}
	return ~SUCCESS_STATE;
}

void prepareKeyWordIdGetter(char* keywords_, char* keywords_re) {
	if (keywords_ == NULL || keywords_re == NULL) return;
	for (char* keywords_re_ = keywords_re, *keywords__ = keywords_; (*keywords_re_ != '\0') ? 1 : (*keywords__ = '\0', 0); (*keywords_re_ != '\\' || (keywords_re_[1] != '+' && keywords_re_[1] != '*' && keywords_re_[1] != '|')) ? *keywords__++ = *keywords_re_ : 0, ++keywords_re_);
}

unsigned int getKeyWordId(char* keywords_, char* lexemStr, unsigned int baseId) {
	if (keywords_ == NULL || lexemStr == NULL) return ~0;
	char* lexemInKeywords_ = keywords_;
	size_t lexemStrLen = strlen(lexemStr);
	if (!lexemStrLen) return ~0;
	for (; lexemInKeywords_ = strstr(lexemInKeywords_, lexemStr), lexemInKeywords_ != NULL && lexemInKeywords_[lexemStrLen] != '|' && lexemInKeywords_[lexemStrLen] != '\0'; ++lexemInKeywords_);
	return lexemInKeywords_ - keywords_ + baseId;
}

char tryToGetKeyWord(struct LexemInfo* lexemInfoInTable) {
	char* keywords_re = (char*)KEYWORDS_RE;
	char keywords_[sizeof(KEYWORDS_RE)] = { '\0' };
	prepareKeyWordIdGetter(keywords_, keywords_re);

	if (std::regex_match(std::string(lexemInfoInTable->lexemStr), std::regex(keywords_re))) {
		lexemInfoInTable->lexemId = getKeyWordId(keywords_, lexemInfoInTable->lexemStr, MAX_VARIABLES_COUNT);
		lexemInfoInTable->tokenType = KEYWORD_LEXEME_TYPE;
		return SUCCESS_STATE;
	}
	return ~SUCCESS_STATE;
}

void setPositions(const char* text, struct LexemInfo* lexemInfoTable) {
	unsigned long long int line_number = 1;
	const char* pos = text;
	if (lexemInfoTable) while (*pos != '\0' && lexemInfoTable->lexemStr[0] != '\0') {
		const char* line_end = strchr(pos, '\n');
		if (!line_end) line_end = text + strlen(text);
		char line_[4096];
		strncpy(line_, pos, line_end - pos);
		line_[line_end - pos] = '\0';
		for (char* found_pos; lexemInfoTable->lexemStr[0] != '\0' && (found_pos = strstr(line_, lexemInfoTable->lexemStr)); ++lexemInfoTable) {
			lexemInfoTable->row = line_number;
			lexemInfoTable->col = found_pos - line_ + 1ull;
		}
		line_number++;
		pos = line_end;
		if (*pos == '\n') pos++;
	}
}

struct LexemInfo lexicalAnalyze(struct LexemInfo* lexemInfoInPtr, char(*identifierIdsTable)[MAX_LEXEM_SIZE]) {
	struct LexemInfo ifBadLexemeInfo;
	if (tryToGetKeyWord(lexemInfoInPtr) == SUCCESS_STATE);
	else if (tryToGetIdentifier(lexemInfoInPtr, identifierIdsTable) == SUCCESS_STATE);
	else if (tryToGetUnsignedValue(lexemInfoInPtr) == SUCCESS_STATE);
	else {
		ifBadLexemeInfo.tokenType = UNEXPEXTED_LEXEME_TYPE;
	}
	return ifBadLexemeInfo;
}

struct LexemInfo tokenize(char* text, struct LexemInfo** lastLexemInfoInTable, char(*identifierIdsTable)[MAX_LEXEM_SIZE], struct LexemInfo(*lexicalAnalyzeFunctionPtr)(struct LexemInfo*, char(*)[MAX_LEXEM_SIZE])) {
	char* tokens_re = (char*)TOKENS_RE;
	std::regex tokens_re_(tokens_re);
	struct LexemInfo ifBadLexemeInfo;
	std::string stringText(text);

	for (std::sregex_token_iterator end, tokenIterator(stringText.begin(), stringText.end(), tokens_re_); tokenIterator != end; ++tokenIterator, ++ * lastLexemInfoInTable) {
		std::string str = *tokenIterator;
		strncpy((*lastLexemInfoInTable)->lexemStr, str.c_str(), MAX_LEXEM_SIZE);
		if ((ifBadLexemeInfo = (*lexicalAnalyzeFunctionPtr)(*lastLexemInfoInTable, identifierIdsTable)).tokenType == UNEXPEXTED_LEXEME_TYPE) break;
	}
	setPositions(text, lexemesInfoTable);
	if (ifBadLexemeInfo.tokenType == UNEXPEXTED_LEXEME_TYPE) {
		strncpy(ifBadLexemeInfo.lexemStr, (*lastLexemInfoInTable)->lexemStr, MAX_LEXEM_SIZE);
		ifBadLexemeInfo.row = (*lastLexemInfoInTable)->row;
		ifBadLexemeInfo.col = (*lastLexemInfoInTable)->col;
	}
	return ifBadLexemeInfo;
}

// Load Source
size_t loadSource(char** text, char* fileName) {
	if (!fileName) { printf("No input file name\r\n"); return 0; }
	FILE* file = fopen(fileName, "rb");
	if (file == NULL) { printf("File not loaded\r\n"); return 0; }
	fseek(file, 0, SEEK_END);
	long fileSize_ = ftell(file);
	if (fileSize_ >= MAX_TEXT_SIZE) { printf("file too large\r\n"); fclose(file); exit(2); }
	size_t fileSize = fileSize_;
	rewind(file);
	*text = (char*)malloc(sizeof(char) * (fileSize + 1));
	if (*text == NULL) { fclose(file); exit(2); }
	size_t result = fread(*text, sizeof(char), fileSize, file);
	(*text)[fileSize] = '\0';
	fclose(file);
	return fileSize;
}

#define MAX_LEXEM_SIZE 1024
int commentRemover(char* text, const char* openStrSpc, const char* closeStrSpc) {
	bool eofAlternativeCloseStrSpcType = false;
	bool explicitCloseStrSpc = true;
	if (!strcmp(closeStrSpc, "\n")) { eofAlternativeCloseStrSpcType = true; explicitCloseStrSpc = false; }
	unsigned int commentSpace = 0;
	unsigned int textLength = strlen(text);
	unsigned int openStrSpcLength = strlen(openStrSpc);
	unsigned int closeStrSpcLength = strlen(closeStrSpc);
	if (!closeStrSpcLength) return -1;
	unsigned char oneLevelComment = 0;
	if (!strncmp(openStrSpc, closeStrSpc, MAX_LEXEM_SIZE)) oneLevelComment = 1;

	for (unsigned int index = 0; index < textLength; ++index) {
		if (!strncmp(text + index, closeStrSpc, closeStrSpcLength) && (explicitCloseStrSpc || commentSpace)) {
			if (commentSpace == 1 && explicitCloseStrSpc) {
				for (unsigned int index2 = 0; index2 < closeStrSpcLength; ++index2) text[index + index2] = ' ';
			} else if (commentSpace == 1 && !explicitCloseStrSpc) index += closeStrSpcLength - 1;
			oneLevelComment ? commentSpace = !commentSpace : commentSpace = 0;
		} else if (!strncmp(text + index, openStrSpc, openStrSpcLength)) {
			oneLevelComment ? commentSpace = !commentSpace : commentSpace = 1;
		}
		if (commentSpace && text[index] != ' ' && text[index] != '\t' && text[index] != '\r' && text[index] != '\n') text[index] = ' ';
	}
	if (commentSpace && !eofAlternativeCloseStrSpcType) return -1;
	return 0;
}

// AST and Syntax Logic
struct ASTNode {
	std::string value;
	bool isTerminal;
	std::vector<ASTNode*> childrens;
	ASTNode* parent;
	ASTNode(const std::string& val, bool isTerminal) : isTerminal(isTerminal), value(val), parent(NULL) {}
	static void redirectLinks(std::vector<ASTNode*>& terminalChildrens) {
		for (ASTNode* node : terminalChildrens) {
			if (node == NULL) continue;
			while (node->parent != NULL) {
				node->parent->childrens.push_back(node);
				ASTNode* parentNode = node->parent;
				node->parent = NULL;
				node = parentNode;
			}
		}
	}
	~ASTNode() { for (ASTNode* child : childrens) delete child; }
};
std::vector<ASTNode*> terminalChildrens;

ASTNode* addASTNodeToParent(ASTNode* parent, char* lexemStr, char isTerminal) {
	ASTNode* node = new(std::nothrow) ASTNode(lexemStr, false);
	if (node == nullptr) exit(0);
	node->parent = parent;
	return node;
}

void printAST(struct LexemInfo* lexemInfoTable, const ASTNode* node, int depth = 0) {
	static int lexemInfoTableIndexForPrintAST = 0;
	if (!node) return;
	if (!depth) lexemInfoTableIndexForPrintAST = 0;
	for (unsigned int depthIndex = 0; depthIndex <= depth; ++depthIndex) std::cout << "    " << "|";
	std::cout << "--";
	if (node->isTerminal) std::cout << "\"" << lexemInfoTable[lexemInfoTableIndexForPrintAST++].lexemStr << "\"";
	else std::cout << node->value;
	std::cout << "\n";
	for (const ASTNode* child : node->childrens) printAST(lexemInfoTable, child, depth + 1);
}

void printASTToFile(struct LexemInfo* lexemInfoTable, const ASTNode* node, std::ofstream& outFile, int depth = 0) {
	static int lexemInfoTableIndexForPrintAST = 0;
	if (!node) return;
	if (!depth) lexemInfoTableIndexForPrintAST = 0;
	for (unsigned int depthIndex = 0; depthIndex <= depth; ++depthIndex) outFile << "    |";
	outFile << "--";
	if (node->isTerminal) outFile << "\"" << lexemInfoTable[lexemInfoTableIndexForPrintAST++].lexemStr << "\"";
	else outFile << node->value;
	outFile << "\n";
	for (const ASTNode* child : node->childrens) printASTToFile(lexemInfoTable, child, outFile, depth + 1);
}

#define MAX_STRSTACK_SIZE 2048
char strStack[MAX_STRSTACK_SIZE][MAX_TOKEN_SIZE] = { '\0' };
ASTNode* nodeStack[MAX_STRSTACK_SIZE] = { NULL };
int strStackFirstFreeElementIndex = 0;

void resetStack() { strStack[0][0] = '\0'; strStackFirstFreeElementIndex = 0; }
char isEmptyStack() { return strStackFirstFreeElementIndex > 0; }
void stackPush(char* stackNewElement, ASTNode* node) {
	if (strStackFirstFreeElementIndex < MAX_STRSTACK_SIZE) {
		nodeStack[strStackFirstFreeElementIndex] = node;
		strncpy(strStack[strStackFirstFreeElementIndex++], stackNewElement, MAX_TOKEN_SIZE);
		return;
	}
	exit(0);
}
ASTNode* stackPop() { if (strStackFirstFreeElementIndex) return nodeStack[--strStackFirstFreeElementIndex]; exit(0); return NULL; }

RHSConteiner* getActualRHSConteinerRHS(Grammar* grammar, struct LexemInfo* currTapeLexemInfoElement, struct LexemInfo* nextTapeLexemInfoElement, char* currStackElement) {
	for (MarkedRule* multiRule = grammar->multiRules; multiRule->firstMarksType; ++multiRule) {
		if (strcmp(multiRule->rule.lhs, currStackElement)) continue;
		for (int firstMarksIndex = 0; multiRule->firstMarks[firstMarksIndex][0] != '\0'; ++firstMarksIndex) {
			bool matchFirst = (currTapeLexemInfoElement->tokenType == IDENTIFIER_LEXEME_TYPE && !strcmp(multiRule->firstMarks[firstMarksIndex], "ident_terminal"))
				|| (currTapeLexemInfoElement->tokenType == VALUE_LEXEME_TYPE && !strcmp(multiRule->firstMarks[firstMarksIndex], "unsigned_value_terminal"))
				|| !strcmp(currTapeLexemInfoElement->lexemStr, multiRule->firstMarks[firstMarksIndex]);
			
			if ((multiRule->firstMarksType == LA_NOT && matchFirst) || (multiRule->firstMarksType == LA_IS && !matchFirst)) continue;

			for (int rhsVariantIndex = 0; multiRule->rule.rhss[rhsVariantIndex].secondMarksType; ++rhsVariantIndex) {
				if (multiRule->rule.rhss[rhsVariantIndex].secondMarks[0][0] == '\0') return multiRule->rule.rhss + rhsVariantIndex;
				for (int secondMarksIndex = 0; multiRule->rule.rhss[rhsVariantIndex].secondMarks[secondMarksIndex][0] != '\0'; ++secondMarksIndex) {
					bool matchSecond = (nextTapeLexemInfoElement->tokenType == IDENTIFIER_LEXEME_TYPE && !strcmp(multiRule->rule.rhss[rhsVariantIndex].secondMarks[secondMarksIndex], "ident_terminal"))
						|| (nextTapeLexemInfoElement->tokenType == VALUE_LEXEME_TYPE && !strcmp(multiRule->rule.rhss[rhsVariantIndex].secondMarks[secondMarksIndex], "unsigned_value_terminal"))
						|| !strcmp(nextTapeLexemInfoElement->lexemStr, multiRule->rule.rhss[rhsVariantIndex].secondMarks[secondMarksIndex]);
					
					if ((multiRule->rule.rhss[rhsVariantIndex].secondMarksType == LA_NOT && matchSecond) || (multiRule->rule.rhss[rhsVariantIndex].secondMarksType == LA_IS && !matchSecond)) continue;
					return multiRule->rule.rhss + rhsVariantIndex;
				}
			}
		}
	}
	return NULL;
}

#define CURRENT_STACK_TOP_ELEMENT strStack[strStackFirstFreeElementIndex - 1]

struct LexemInfo* syntaxLL2(Grammar* grammar, char* ruleName, struct LexemInfo* lexemInfoTable, ASTNode** baseASTNode, struct LexemInfo** badLexemInfo) {
	struct LexemInfo* currTapeElement, * nextTapeElement;
	terminalChildrens.resize(0);
	currTapeElement = lexemInfoTable;
	nextTapeElement = lexemInfoTable + 1;
	resetStack();
	stackPush(ruleName, *baseASTNode = addASTNodeToParent(NULL, ruleName, false));

	while (isEmptyStack()) {
		if ((currTapeElement->tokenType == IDENTIFIER_LEXEME_TYPE && !strcmp(CURRENT_STACK_TOP_ELEMENT, "ident_terminal"))
			|| (currTapeElement->tokenType == VALUE_LEXEME_TYPE && !strcmp(CURRENT_STACK_TOP_ELEMENT, "unsigned_value_terminal"))
			|| !strcmp(currTapeElement->lexemStr, CURRENT_STACK_TOP_ELEMENT)) {
			currTapeElement++; nextTapeElement++;
			ASTNode* node = stackPop();
			if (node) node->isTerminal = true;
			terminalChildrens.push_back(node);
		} else {
			RHSConteiner* rhsConteiner = getActualRHSConteinerRHS(grammar, currTapeElement, nextTapeElement, CURRENT_STACK_TOP_ELEMENT);
			if (rhsConteiner == NULL) {
				if (badLexemInfo != NULL) *badLexemInfo = currTapeElement;
				return currTapeElement;
			}
			ASTNode* parent = stackPop();
			for (int rhsElementIndex = rhsConteiner->rhs_count - 1; rhsElementIndex >= 0; --rhsElementIndex) {
				stackPush(rhsConteiner->rhs[rhsElementIndex], addASTNodeToParent(parent, rhsConteiner->rhs[rhsElementIndex], false));
			}
		}
	}
	ASTNode::redirectLinks(terminalChildrens);
	return currTapeElement;
}

int syntaxAnalyze(struct LexemInfo* lexemInfoTable, Grammar* grammar, char syntaxlAnalyzeMode, char* astFileName, char* errorMessagesPtrToLastBytePtr, bool viewAST) {
	struct ASTNode* astRoot = NULL;
	struct LexemInfo* unexpectedLexemfailedTerminal = NULL;
	struct LexemInfo* lastLexemInfo = syntaxLL2(grammar, grammar->start_symbol, lexemInfoTable, &astRoot, &unexpectedLexemfailedTerminal);

	if (lastLexemInfo->lexemStr[0] == '\0') {
		if (viewAST) printAST(lexemInfoTable, astRoot);
		std::ofstream astOFStream(astFileName, std::ofstream::out);
		printASTToFile(lexemInfoTable, astRoot, astOFStream);
		astOFStream.close();
		return SUCCESS_STATE;
	} else {
		printf("Parse failed.\r\n    Unexpected terminal \"%s\" on line %lld at position %lld.\r\n", lastLexemInfo->lexemStr, lastLexemInfo->row, lastLexemInfo->col);
		return ~SUCCESS_STATE;
	}
}

// MAIN FUNCTION - Renamed for Wrapper
int main_syntax(int argc, char* argv[]) {
	char* text;
	char fileName[128] = DEFAULT_INPUT_FILE;
	char choice[2] = { fileName[0], fileName[1] };
	system("CLS");
	std::cout << "Enter file name(Enter \"" << choice[0] << "\" to use default \"" DEFAULT_INPUT_FILE "\"):";
	std::cin >> fileName;
	if (fileName[0] == choice[0] && fileName[1] == '\0') fileName[1] = choice[1];
	
	size_t sourceSize = loadSource(&text, fileName);
	if (!sourceSize) { (void)getchar(); return 0; }

	printf("Original source:\r\n-----------------------------------\r\n%s\r\n-----------------------------------\r\n\r\n", text);
	
	// COMMENT REMOVER FOR VARIANT 2 (?? ... ??)
	int commentRemoverResult = commentRemover(text, "??", "??");
	if (commentRemoverResult) { printf("Comment error\n"); return 0; }
	
	printf("Source after comment removing:\r\n-----------------------------------\r\n%s\r\n-----------------------------------\r\n\r\n", text);

	struct LexemInfo ifBadLexemeInfo = tokenize(text, &lastLexemInfoInTable, identifierIdsTable, lexicalAnalyze);

	if (ifBadLexemeInfo.tokenType == UNEXPEXTED_LEXEME_TYPE) {
		printf("Lexical analysis detected unexpected lexeme\r\n");
		printLexemes(&ifBadLexemeInfo, 1);
	} else {
		printLexemes(lexemesInfoTable, 0);
		if (SUCCESS_STATE != syntaxAnalyze(lexemesInfoTable, &grammar, 0, (char*)AST_OUTPUT_FILE, (char*)&errorMessagesPtrToLastBytePtr, true)) {
			printf("\nParsing Error.\n");
		}
	}
	free(text);
	(void)getchar();
	
	#ifdef RERUN_MODE
	printf("\nEnter 'y' to rerun: ");
	char val = getchar();
	if(val == 'y' || val == 'Y') system((std::string("\"") + argv[0] + "\"").c_str());
	#endif
	return 0;
}
