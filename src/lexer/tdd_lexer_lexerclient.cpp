/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#include "include/tdd_lexer_lexerclient.hpp"
#include "include/tdd_lexer_SyntaxToken.hpp"
#include <string>
#include <vector>
#include <cctype>


using namespace std;
using namespace TDD;
using namespace TDD::Lexer;

char LexerClient::GetCurrent()
{
	if (m_position >= m_queryText.length())
	{
		return '\0';
	}
	else {
		return m_queryText[m_position];
	}
}

void LexerClient::Next()
{
	m_position++;
}

SyntaxToken LexerClient::NextToken()
{
	int start = m_position;
	if (std::isdigit(GetCurrent()))
	{
		while (std::isdigit(GetCurrent()))
		{
			Next();
		}
		int tokenLength = m_position - start;
		string tokenString = m_queryText.substr(start,tokenLength);
		return  SyntaxToken(SyntaxKind::NumberToken, start, tokenString);
	}

	else if (std::isspace(GetCurrent()))
	{
		int start = m_position;
		while (std::isspace(GetCurrent()))
		{
			Next();
		}
		int tokenLength = m_position - start;
		string tokenString = m_queryText.substr(start, tokenLength);
		return SyntaxToken(SyntaxKind::WhitespaceToken, start, tokenString);
	}
	else if (GetCurrent() == '+')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return SyntaxToken(SyntaxKind::PlusToken, start, syntaxTokenStr);
	}

	else if (GetCurrent() == '*')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  SyntaxToken(SyntaxKind::MulToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == '\0')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  SyntaxToken(SyntaxKind::EndOfFileToken, start, syntaxTokenStr);
	}
	else
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  SyntaxToken(SyntaxKind::InvalidToken, start, syntaxTokenStr);
	}
}

SyntaxTokenList LexerClient::Init() 
{
	vector<SyntaxToken> tokenList{};
	SyntaxToken currentToken = NextToken();
	 do
	{
		 if (currentToken.GetKind() != SyntaxKind::EndOfFileToken)
		 {
			 tokenList.emplace_back(currentToken);
		 }
		 currentToken = NextToken();
	 } while (currentToken.GetKind() != SyntaxKind::EndOfFileToken);
	 return tokenList;
}
