#!/usr/bin/python3
def search_replace(my_list, search, replace):
    result_list = []
    for element in my_list:
        if element == search:
            result_list.append(replace)
        else:
            result_list.append(element)
    return result_list

