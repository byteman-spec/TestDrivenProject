/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_UTILS_COMPARATOR_COMPARATORUTILS_HPP
#define	TDD_UTILS_COMPARATOR_COMPARATORUTILS_HPP
#include <string>
#include <vector>
#include <memory>
#include <type_traits> // for std::enable_if
#include "../../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"

using namespace std;

namespace TDD {

	namespace Utils {

		namespace Comparator {

			template <typename T>
			class ComparatorUtils
			{
			public:

				static bool SharedPtr_Comparator( T leftPtr,  T rightPtr)
				{
					if (!leftPtr && !rightPtr) return true;
					if (!leftPtr || !rightPtr) return false;

					return *leftPtr == *rightPtr;
				}

				static bool SharedPtr_ComparatorList( vector<T> leftPtr,  vector<T> rightPtr)
				{

					if (leftPtr.size() != leftPtr.size()) return false;
					for (size_t i = 0; i < leftPtr.size(); ++i)
					{
						if (!SharedPtr_Comparator(leftPtr[i], rightPtr[i]))
						{
							return false;
						}
					}
					return true;
				}

			};


			
		}
	}
}
#endif // !TDD_UTILS_COMPARATOR_COMPARATORUTILS_HPP
