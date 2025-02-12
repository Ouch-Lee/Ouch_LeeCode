## String相关的知识

# C++ STL String 常用 API

| API                   | 功能描述                                                     | 简单用法                                                     |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `std::string`         | 创建一个字符串对象                                           | `std::string str;` 或 `std::string str = "Hello";`           |
| `size()` / `length()` | 返回字符串的长度（字符数）                                   | `str.size();` 或 `str.length();`                             |
| `empty()`             | 判断字符串是否为空，返回布尔值                               | `str.empty();`                                               |
| `c_str()`             | 返回指向 C 风格字符串（const char*）的指针                   | `str.c_str();`                                               |
| `clear()`             | 清空字符串内容                                               | `str.clear();`                                               |
| `append()`            | 向字符串末尾追加内容                                         | `str.append(" World");` 或 `str += " World";`                |
| `substr()`            | 提取子字符串                                                 | `str.substr(0, 5);` （从位置 0 开始，长度为 5 的子字符串）   |
| `find()`              | 查找指定子字符串的第一次出现位置（返回索引）                 | `str.find("lo");` （返回子字符串 "lo" 在 `str` 中的位置）    |
| `rfind()`             | 查找指定子字符串的最后一次出现位置（返回索引）               | `str.rfind("lo");`                                           |
| `replace()`           | 替换指定范围内的字符                                         | `str.replace(0, 5, "Hi");` （替换从位置 0 开始，长度 5 的字符） |
| `erase()`             | 删除指定位置或范围内的字符                                   | `str.erase(0, 5);` （删除从位置 0 开始，长度 5 的字符）      |
| `insert()`            | 在指定位置插入字符或子字符串                                 | `str.insert(5, " World");`                                   |
| `at()`                | 访问指定位置的字符，检查越界                                 | `str.at(2);` （访问索引为 2 的字符）                         |
| `[]`                  | 通过下标访问字符（不做越界检查）                             | `str[2];` （访问索引为 2 的字符）                            |
| `compare()`           | 比较两个字符串，返回整数值（0 表示相等，负值表示小于，正值表示大于） | `str.compare("Hello");`                                      |
| `push_back()`         | 向字符串末尾添加一个字符                                     | `str.push_back('!');`                                        |
| `pop_back()`          | 删除字符串的最后一个字符                                     | `str.pop_back();`                                            |
| `resize()`            | 改变字符串的大小，如果扩展会用指定字符填充                   | `str.resize(10, 'x');`                                       |
| `find_first_of()`     | 查找任意字符首次出现的位置                                   | `str.find_first_of("aeiou");`                                |
| `find_last_of()`      | 查找任意字符最后一次出现的位置                               | `str.find_last_of("aeiou");`                                 |
| `find_first_not_of()` | 查找第一个不属于指定字符集的位置                             | `str.find_first_not_of("aeiou");`                            |
| `find_last_not_of()`  | 查找最后一个不属于指定字符集的位置                           | `str.find_last_not_of("aeiou");`                             |
| `swap()`              | 交换两个字符串的内容                                         | `str1.swap(str2);`                                           |
| `resize()`            | 修改字符串的长度，扩展或缩短                                 | `str.resize(10);`                                            |

## 题目笔记

1. 反转string

   这个太简单了，直接两头各一个指针，也即双指针法，直接跑一遍就行了

2. 反转string2

   这个也不难，只需要一次for循环就可以解决问题，主要是想清楚，最后落单的几个字符串怎么处理