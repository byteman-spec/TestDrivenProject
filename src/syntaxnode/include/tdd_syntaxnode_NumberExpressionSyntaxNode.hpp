/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_SYNTAXNODE_NUMBEREXPRESSIONSYNTAXNODE_HPP
#define	TDD_SYNTAXNODE_NUMBEREXPRESSIONSYNTAXNODE_HPP
#include <string>
#include <vector>
#include "tdd_syntaxnode_SyntaxToken.hpp"
#include "tdd_syntaxnode_ExpressionSyntaxNode.hpp"
#include "../../utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"

using namespace std;
using namespace TDD::Utils::Comparator;

namespace TDD {

	namespace SyntaxNode {

		class NumberExpressionSyntaxNode;
		using NumberExpressionSyntaxNodePtr = shared_ptr<NumberExpressionSyntaxNode>;

		class NumberExpressionSyntaxNode : public ExpressionSyntaxNode
		{

		private : 
			SyntaxTokenPtr m_numberSyntaxToken;
		public:
			
			NumberExpressionSyntaxNode(SyntaxTokenPtr syntaxToken) : m_numberSyntaxToken(syntaxToken)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::NumberExpressionSyntaxNodeToken;
			}

			vector<ISyntaxNodePtr> GetChildren() const override
			{
				vector<ISyntaxNodePtr> childrenList;
				childrenList.emplace_back(m_numberSyntaxToken);
				return childrenList;
			}

			bool operator==(const ISyntaxNode& baseSyntaxNode) const override
			{
				if (const NumberExpressionSyntaxNode* castedNumberExpressionSyntaxNode = static_cast<const NumberExpressionSyntaxNode*>(&baseSyntaxNode))
				{
					if (ComparatorUtils<SyntaxTokenPtr>::SharedPtr_Comparator(m_numberSyntaxToken, castedNumberExpressionSyntaxNode->m_numberSyntaxToken))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				return false;
			}


		};
	}
}
#endif // !TDD_SYNTAXNODE_NUMBEREXPRESSIONSYNTAXNODE_HPP
