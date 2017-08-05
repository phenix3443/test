[参考教程](http://wowubuntu.com/markdown/)

title

# heading 1
## heading 2
### heading 3
#### heading 4
##### heading 5
###### heading 6

# paragraph

this is paragraph 1.

this is paragraph 2, with broken
lines

# blockquote

> This is blockquote with two paragraphs. this is line 1,
and this is line two, they all in one line.
>> this is two level blockquote.
>>> this is three level blockquote.

# order list
## with star, plus, minus

* star
+ plus
- minus

## blank lines:

+ item 1

+ item 2

+ item 3

## paragraph
* item 1
+ This is a list item with two paragraphs.

	This is the second paragraph in the list item. You're
only required to indent the first line. Lorem ipsum dolor
sit amet, consectetuer adipiscing elit.
* item 3 is a long sentence with broken lines.
  line 2 indent here.
  line 3 indent here.

# order list

1. item 1
3. item 3
2. item 2
4. item 4

# block
normal lines.

	block lines

# split line

-----

# link

This is [an example](http://example.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.

# footlink
This is [an example][1] reference-style link.

[1]: http://www.baidu.com (optional title)

# em
*斜体*

**粗体**

***加粗***

~~删除线~~

# code
there is a code snipt `printf()` in this line.

next is a code block

``` c++
int main() {
	std::cout << "hello, world!" << std::endl;
}
```

# image
![test image]()

# link
<http://www.baidu.com>

[baidu](http://www.baidu.com)

# 表格
