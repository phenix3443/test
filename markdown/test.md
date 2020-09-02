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

# block
normal lines.

    block lines
    
# order list

1. item 1

3. 数字的顺序并不会影响生成的列表序列。

2. item 3
4. This is a list item with two paragraphs.

    This is the second paragraph in the list item. You're
only required to indent the first line. Lorem ipsum dolor
sit amet, consectetuer adipiscing elit.

# unorder list with star, plus, minus
* star
+ plus
- minus

# checkbox
* [ ] item1
* [x] item2
    
  
# horizon line

-------------------------------------------------------------------------------

# 表格

| 选项 | 测试      |
|:-----|:-----------:|
|   IP | 127.0.0.1 |
| Port | 8080      |

# image
![七夕](https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/u=2879587941,3096524536&fm=26&gp=0.jpg "七夕")


# 文法
*斜体*

**Bold**

~~删除线~~


> This is blockquote with two paragraphs. this is line 1,
and this is line two, they all in one line.
>> this is two level blockquote.
>>> this is three level blockquote.    

there is a code snipt `printf()` in this line.

``` python
print("this is a code block")
```

下面有一些注释都看不到：
<!--Some text to show that the reference links can follow later:-->

[google-ref]: http://www.google.com
[1]: http://www.baidu.com


# link
<http://www.baidu.com>

[inline url](https://www.google.com "google")

[引用相对路径的文件](image.jpg)

[字符引用][google-ref]

[数字引用][1]

[引用其他section，可能只有Github支持][#horizon line]

[只有链接文本][]

[[wiki links]]




# footlink
You can add footnotes to your text as follows.[^1]




[^1]: This is my awesome footnote.
