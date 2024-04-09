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
using namespace std;

namespace TDD {

	namespace SyntaxNode {

		class NumberExpressionSyntaxNode : public ExpressionSyntaxNode
		{

		private : 
			SyntaxToken m_numberSyntaxToken;
		public:
			
			NumberExpressionSyntaxNode(const SyntaxToken& syntaxToken) : m_numberSyntaxToken(syntaxToken)
			{

			}

			SyntaxKind GetKind() override
			{
				return SyntaxKind::ExpressionSyntaxNodeToken;
			}

			vector<ISyntaxNode> GetChildren() override
			{
				vector<ISyntaxNode> childrenList;
				childrenList.emplace_back(m_numberSyntaxToken);
				return childrenList;
			}


		};
	}
}
#endif // !TDD_SYNTAXNODE_NUMBEREXPRESSIONSYNTAXNODE_HPP
