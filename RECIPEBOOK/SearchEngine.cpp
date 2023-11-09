#include "SearchEngine.h"

std::vector<Recipe> SearchEngine::Start(SearchData searchData)
{
    if (searchData.operationType) return SearchUnion(searchData);
    else return SearchIntersection(searchData);
}

std::vector<Recipe> SearchEngine::SearchUnion(SearchData searchData)
{
    std::vector<Recipe> searchResultArray;

    return searchResultArray;
}

std::vector<Recipe> SearchEngine::SearchIntersection(SearchData searchData)
{
    std::vector<Recipe> searchResultArray;
    
    return searchResultArray;
}