/*################################################################################################
#Header for BinaryExpressionSyntaxNode															##
#																								##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for BinaryExpressionSyntaxNode				##
#14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
#define	TDD_SYNTAXNODE_BINARYEXPRESSIONSYNTAXNODE_HPP
#include <string>
#include <vector>
#include "tdd_syntaxnode_SyntaxToken.hpp"
#include "tdd_syntaxnode_ExpressionSyntaxNode.hpp"
#include "../../utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"
using namespace std;
using namespace TDD::Utils::Comparator;

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

			BinaryExpressionSyntaxNode( ExpressionSyntaxNodePtr left,  SyntaxTokenPtr syntaxToken, ExpressionSyntaxNodePtr right) :
				m_operatorSyntaxToken(syntaxToken), m_left (left) , m_right (right)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::BinaryExpressionSyntaxNodeToken;
			}

			vector<ISyntaxNodePtr> GetChildren() const override
			{
				vector <ISyntaxNodePtr> childrenList{};
				childrenList.emplace_back(m_left);
				childrenList.emplace_back(m_operatorSyntaxToken);
				childrenList.emplace_back(m_right);
				return childrenList;
			}


			bool operator==(const ISyntaxNode& baseSyntaxNode) const override
			{
				if (const BinaryExpressionSyntaxNode* castedBinarySyntaxExpressionToken = static_cast<const BinaryExpressionSyntaxNode*>(&baseSyntaxNode))
				{
					if (ComparatorUtils<ExpressionSyntaxNodePtr>::SharedPtr_Comparator(m_left,castedBinarySyntaxExpressionToken->m_left)
						&& ComparatorUtils<SyntaxTokenPtr>::SharedPtr_Comparator(m_operatorSyntaxToken, castedBinarySyntaxExpressionToken->m_operatorSyntaxToken)
						&& ComparatorUtils<ExpressionSyntaxNodePtr>::SharedPtr_Comparator(m_right, castedBinarySyntaxExpressionToken->m_right))
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
