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
#include "tdd_syntaxnode_ExpressionSyntaxNode.hpp"
using namespace std;

namespace TDD {

	namespace SyntaxNode {

		class BinaryExpressionSyntaxNode;
		using BinaryExpressionSyntaxNodePtr = shared_ptr<BinaryExpressionSyntaxNode>;

		class BinaryExpressionSyntaxNode : public ExpressionSyntaxNode
		{

		private : 
			ExpressionSyntaxNodePtr m_left;
			ExpressionSyntaxNodePtr m_right;
			SyntaxTokenPtr m_operatorSyntaxToken;
		public:
			
			BinaryExpressionSyntaxNode(const ExpressionSyntaxNodePtr left,const ExpressionSyntaxNodePtr right,const SyntaxTokenPtr syntaxToken) : 
				m_operatorSyntaxToken(syntaxToken), m_left (left) , m_right (right)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::BinaryExpressionSyntaxNodeToken;
			}

			vector<ISyntaxNodePtr> GetChildren() override
			{
				vector <ISyntaxNodePtr> left = m_left->GetChildren();
				vector <ISyntaxNodePtr> operatorToken = m_operatorSyntaxToken->GetChildren();
				vector <ISyntaxNodePtr> right = m_right->GetChildren();

				left.insert(left.end(), operatorToken.begin(), operatorToken.end());
				left.insert(left.end(), right.begin(), right.end());
				return left;
			}


		};
	}
}
#endif // !TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
