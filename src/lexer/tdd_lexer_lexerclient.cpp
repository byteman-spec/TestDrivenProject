/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#include "include/tdd_lexer_lexerclient.hpp"
#include "../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include <string>
#include <vector>
#include <cctype>


using namespace std;
using namespace TDD;
using namespace TDD::Lexer;
using namespace TDD::SyntaxNode;

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

SyntaxTokenPtr LexerClient::NextToken()
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
		return  make_shared<SyntaxToken>(SyntaxKind::NumberToken, start, tokenString);
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
		return make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, start, tokenString);
	}
	else if (GetCurrent() == '+')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return make_shared<SyntaxToken>(SyntaxKind::PlusToken, start, syntaxTokenStr);
	}

	else if (GetCurrent() == '*')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::StarToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == '\0')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::EndOfFileToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == '-')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::HyphenToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == '(')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::OpenParanthesisToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == ')')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::CloseParanthesisToken, start, syntaxTokenStr);
	}
	else if (GetCurrent() == '/')
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::SlashToken, start, syntaxTokenStr);
	}
	else
	{
		auto syntaxTokenStr = std::string(1, GetCurrent());
		Next();
		return  make_shared<SyntaxToken>(SyntaxKind::InvalidToken, start, syntaxTokenStr);
	}
}

SyntaxTokenList LexerClient::Init() 
{
	vector<SyntaxTokenPtr> tokenList{};
	SyntaxTokenPtr currentToken = NextToken();
	 do
	{
		 if (currentToken->GetKind() != SyntaxKind::EndOfFileToken)
		 {
			 tokenList.emplace_back(currentToken);
		 }
		 currentToken = NextToken();
	 } while (currentToken->GetKind() != SyntaxKind::EndOfFileToken);
	 return tokenList;
}

SyntaxTokenList LexerClient::Init(const string& queryText, bool force ) 
{
	if (m_queryText.empty() || force)
	{
		m_queryText = queryText;
		m_position = 0;
		return Init();
	}
	else
	{
		return Init();
	}

}