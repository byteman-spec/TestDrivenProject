/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
#define	TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
#include <string>
#include <vector>
#include "tdd_syntaxnode_SyntaxToken.hpp"
using namespace std;

namespace TDD {

	namespace SyntaxNode {

		class BinaryExpressionSyntaxNode : public ExpressionSyntaxNode
		{

		private : 
			ExpressionSyntaxNode m_left;
			ExpressionSyntaxNode m_right;
			SyntaxToken m_operatorSyntaxToken;
		public:
			
			BinaryExpressionSyntaxNode(const ExpressionSyntaxNode& left,const ExpressionSyntaxNode& right,const SyntaxToken& syntaxToken) : 
				m_operatorSyntaxToken(syntaxToken), m_left (left) , m_right (right)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::BinaryExpressionSyntaxNode;
			}

			vector<ISyntaxNode> GetChildren() override
			{
				vector <ISyntaxNode> left = m_left.GetChildren();
				vector <ISyntaxNode> operatorToken = m_operatorSyntaxToken.GetChildren();
				vector <ISyntaxNode> right = m_right.GetChildren();

				left.insert(left.end(), operatorToken.begin(), operatorToken.end());
				left.insert(left.end(), right.begin(), right.end());
				return left;
			}


		};
	}
}
#endif // !TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
