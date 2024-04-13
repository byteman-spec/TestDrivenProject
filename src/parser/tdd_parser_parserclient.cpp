/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#include "include/tdd_parser_parserclient.hpp"
#include "../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../syntaxnode/include/tdd_syntaxnode_ExpressionSyntaxNode.hpp"
#include "../syntaxnode/include/tdd_syntaxnode_NumberExpressionSyntaxNode.hpp"
#include "../syntaxnode/include/tdd_syntaxnode_BinaryExpressionSyntaxNode.hpp"
#include <string>
#include <vector>
#include <cctype>


using namespace std;
using namespace TDD;
using namespace TDD::Parser;
using namespace TDD::SyntaxNode;

SyntaxTokenPtr ParserClient::GetCurrent()
{
	return Peek(0);
}

void ParserClient::Next()
{
	m_position++;
}

SyntaxTokenPtr ParserClient::GetCurrentInc()
{
	int start = m_position;
	if (m_position >= m_syntaxTokenPtrs.size())
	{
		return m_syntaxTokenPtrs[m_syntaxTokenPtrs.size() - 1];
	}
	m_position++;
	return m_syntaxTokenPtrs[start];
}

SyntaxTokenPtr ParserClient::Peek(const int& offset)
{
	int index = m_position + offset;
	if (index >= m_syntaxTokenPtrs.size())
	{
		return m_syntaxTokenPtrs[m_syntaxTokenPtrs.size() - 1];
	}
	return m_syntaxTokenPtrs[index];
}

SyntaxTokenPtr ParserClient::Match(const SyntaxKind& kind)
{
	if (GetCurrent()->GetKind() == kind)
	{
		return GetCurrentInc();
	}
	return make_shared<SyntaxToken>(kind, m_position, "");;
}

ParserClient::ParserClient(ILexerPtr lexer) : m_lexer(lexer)
{
	m_position = 0;
	m_queryText = m_lexer->GetQueryString();
	m_syntaxTokenPtrs = m_lexer->Init(m_queryText,true);
}

ParserClient::ParserClient() 
{
	m_position = 0;
	m_queryText = "";
	m_lexer = nullptr;
	m_syntaxTokenPtrs.clear();
}

ExpressionSyntaxNodePtr ParserClient::Parse()
{	
	ExpressionSyntaxNodePtr left = ParsePrimaryExpression();
	while (GetCurrent()->GetKind() == SyntaxKind::PlusToken
		|| GetCurrent()->GetKind() == SyntaxKind::HyphenToken)
	{
		SyntaxTokenPtr operatorToken = GetCurrentInc();
		ExpressionSyntaxNodePtr right = ParsePrimaryExpression();
		auto temp = make_shared<BinaryExpressionSyntaxNode>(left,operatorToken,right);
		left = temp;
	}
	return left;
}

ExpressionSyntaxNodePtr ParserClient::ParsePrimaryExpression()
{
	SyntaxTokenPtr numberSyntaxToken = Match(SyntaxKind::NumberToken);
	return make_shared<NumberExpressionSyntaxNode>(numberSyntaxToken);
}

ExpressionSyntaxNodePtr ParserClient::Parse(const string& queryText, SyntaxTokenList tokenList ,bool force)
{
	if ((m_queryText.empty() && m_syntaxTokenPtrs.empty() )|| force)
	{
		m_queryText = queryText;
		m_position = 0;
		m_syntaxTokenPtrs = tokenList;
		return Parse();
	}
	else
	{
		return Parse();
	}
}