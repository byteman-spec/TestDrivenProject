///*################################################################################################
//Header for lexer created 																		##
//#HISTORY																						##
//#DATE						#USERNAME		#DESC												##
//#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
//#################################################################################################*/
//#include "include/tdd_parser_parserclient.hpp"
//#include "../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
//#include "../syntaxnode/include/tdd_syntaxnode_ExpressionSyntaxNode.hpp"
//#include "../syntaxnode/include/tdd_syntaxnode_NumberExpressionSyntaxNode.hpp"
//#include <string>
//#include <vector>
//#include <cctype>
//
//
//using namespace std;
//using namespace TDD;
//using namespace TDD::Parser;
//using namespace TDD::SyntaxNode;
//
//SyntaxToken ParserClient::GetCurrent()
//{
//	return Peek(0);
//}
//
//void ParserClient::Next()
//{
//	m_position++;
//}
//
//SyntaxToken ParserClient::GetCurrentInc()
//{
//	int start = m_position;
//	if (m_position >= m_syntaxTokens.size())
//	{
//		return m_syntaxTokens[m_syntaxTokens.size() - 1];
//	}
//	m_position++;
//	return m_syntaxTokens[start];
//}
//
//SyntaxToken ParserClient::Peek(const int& offset)
//{
//	int index = m_position + offset;
//	if (index >= m_syntaxTokens.size())
//	{
//		return m_syntaxTokens[m_syntaxTokens.size() - 1];
//	}
//	return m_syntaxTokens[index];
//}
//
//SyntaxToken ParserClient::Match(const SyntaxKind& kind)
//{
//	if (GetCurrent().GetKind() == kind)
//	{
//		return GetCurrentInc();
//	}
//
//	SyntaxToken requiredToken(kind, m_position, NULL);
//	return requiredToken;
//}
//
//ExpressionSyntaxNode ParserClient::Parse(const string& queryText)
//{	
//	m_queryText = queryText;
//	m_syntaxTokens = m_lexer.Init();
//	ExpressionSyntaxNode left = ParsePrimaryExpression();
//	while (GetCurrent().GetKind() == SyntaxKind::PlusToken
//		|| GetCurrent().GetKind() == SyntaxKind::HyphenToken)
//	{
//		SyntaxToken operatorToken = GetCurrentInc();
//		ExpressionSyntaxNode right = ParsePrimaryExpression();
//		BinaryExpressionSyntaxNode temp(left, operatorToken, right);
//		left = temp;
//	}
//	return left;
//}
//
//ExpressionSyntaxNode ParserClient::ParsePrimaryExpression()
//{
//	SyntaxToken numberSyntaxToken = Match(SyntaxKind::NumberToken);
//	return  NumberExpressionSyntaxNode(numberSyntaxToken);
//}