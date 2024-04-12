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
			static vector <ISyntaxNodePtr> m_leftList;
			static vector <ISyntaxNodePtr> m_operatorTokenList;
			static vector <ISyntaxNodePtr> m_rightList;

			BinaryExpressionSyntaxNode( ExpressionSyntaxNodePtr left, ExpressionSyntaxNodePtr right, SyntaxTokenPtr syntaxToken) : 
				m_operatorSyntaxToken(syntaxToken), m_left (left) , m_right (right)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::BinaryExpressionSyntaxNodeToken;
			}

			void InitiateChildrenList()
			{

				m_leftList = m_left->GetChildren();
				if (GetKind() == SyntaxKind::BinaryExpressionSyntaxNodeToken)
				{
					m_operatorTokenList.clear();
					m_rightList.clear();
				}
				m_operatorTokenList.emplace_back(m_operatorSyntaxToken);
				if (GetKind() == SyntaxKind::BinaryExpressionSyntaxNodeToken)
				{
					m_rightList.clear();
				}
				m_rightList = m_right->GetChildren();
			}

			vector<ISyntaxNodePtr> GetChildren() override
			{
				InitiateChildrenList();
				m_leftList.insert(m_leftList.end(), m_operatorTokenList.begin(), m_operatorTokenList.end());
				m_leftList.insert(m_leftList.end(), m_rightList.begin(), m_rightList.end());
				return m_leftList;
			}

			bool operator==(const ISyntaxNode& baseSyntaxNode) const override
			{
				if (const BinaryExpressionSyntaxNode* castedBinarySyntaxExpressionToken = static_cast<const BinaryExpressionSyntaxNode*>(&baseSyntaxNode))
				{
					//if (m_left == castedBinarySyntaxExpressionToken->m_left &&
					//	m_operatorSyntaxToken == castedBinarySyntaxExpressionToken->m_operatorSyntaxToken &&
					//	m_operatorSyntaxToken == castedBinarySyntaxExpressionToken->m_right)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		};
	}
}
   
#endif // !TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
