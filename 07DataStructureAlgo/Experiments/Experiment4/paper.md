# An Algorithm for the Organization of Information  
**G. M. Adel'son-Vel'skii and E. M. Landis**

In the present article, we discuss the organization of information contained in the cells of an automatic calculating machine. A three-address machine will be used for this study.

## Statement of the Problem  
The information enters a machine in sequence from a certain reserve. The information element is contained in a group of cells arranged one after the other. A certain number (the information estimate), which is different for different elements, is contained in the information element. The information must be organized in the memory of the machine in such a way that, at any moment, a large number of operations are not required to scan the information with the given evaluation and to record the new information element.

An algorithm is proposed in which both the search and the recording are carried out in \( \log N \) operations, where \( N \) is the number of information elements that have entered at a given moment. A part of the memory of the machine is set aside to store the incoming information. The information elements are arranged there in their order of entry. Moreover, in another part of the memory, a **reference board** is formed, with each cell corresponding to one of the information elements. 

The reference board is a **dyadic tree** (Figure 1a), where each of its cells has no more than one left and one right subordinate cell. Direct subordination induces partial ordering. For each cell in the tree, all the cells subordinate to a left (or right) directly subordinate cell are arranged further to the left (or right) than the given cell. Additionally, there is a **head cell** to which all others are subordinate.

By transitivity, the concept of "further to the left" or "further to the right" extends to all cell pairs, and this aggregate becomes ordered. The given order of cells in a reference board should coincide with the arrangement of the estimates of the corresponding information elements (considering estimates to be increasing from left to right).

In the first address of each cell in the reference board, a location is indicated where the corresponding information element is located. The addresses of the cells directly subordinate on the left and right are located in the second and third addresses, respectively. If a cell has no directly subordinate cells on either side, there is a zero in the corresponding address. The head address is stored in a certain fixed cell.

## Tree Structure and Admissibility
Let us call the sequence of cells of the tree a **chain**, where each previous cell is directly subordinate to the following one. For each tree cell, we designate the **length of the left (right) branch** as the maximum length of the chain consisting of cells subordinate to the given one and located further to the left (right). Any chain whose length equals the length of the branch is called the **branch pivot**.

An **admissible tree** is defined such that, for each of its cells, the length of the left branch differs from the length of the right branch by no more than one unit (Figure 1b). Each cell of the address board contains orders for the branch lengths. If the left branch is longer than the right, the order is `1, 0`. If the right branch is longer, the order is `0, 1`. If they are equal, the order is `0, 0`. If there are no subordinate cells on either side, the branch length on that side is considered zero.

![Figure 1](#)  
![Figure 2](#)

The recording algorithm ensures that at each moment, the reference board is an admissible tree.

### Lemma 1:  
Let the number of cells in the admissible tree be \( N \). Then, the maximum length of the branch is no greater than \( \frac{3}{2} \log_2(N + 1) \).

**Proof:**  
Let \( N_n \) be the minimum number of cells in the admissible tree when the maximum length of the branch is \( n \). It can be easily shown that:

\[
N_n = N_{n-1} + N_{n-2} + 1
\]

Solving this equation for finite remainders, we get:

\[
N_n = \frac{(1 + \sqrt{5})^n}{2^n} - \frac{(1 - \sqrt{5})^n}{2^n} - 1
\]

Thus,  
\[
n \leq \log_2(N + 1)
\]  
\( \square \)

## Search Algorithm
The search algorithm for the information element with the given estimate follows these steps:

1. Compare the given estimate with the estimate of the information element corresponding to the head.
2. Based on the result of the comparison, compare the given estimate with the estimate of the element corresponding to the left or right subordinate cell of the head.
3. After \( k \) comparison steps, if \( m < m_i \) (or \( m > m_i \)), then at step \( k + 1 \), a comparison is made with the element subordinate to the cell on the left (or right). If \( m = m_i \), the search is complete.

Since the number of operations is proportional to the number of comparisons, and each comparison has three possible outcomes, Lemma 1 implies that the number of operations required for the search is no greater than \( C \log_2(N) \).

## Insertion and Tree Reorganization
Let us describe the algorithm for maintaining the reference board as an admissible tree:

1. When the first information element enters, it is stored in a certain cell, and this cell becomes the **head**.
2. If a new information element enters, apply the search algorithm to find the appropriate position for the new element.
3. If the new element is already present, the tree remains unchanged. Otherwise, insert the new cell in the reference board as a direct subordinate of the appropriate cell, either on the left or right.
4. After insertion, adjust the branch lengths in the recorded chain to maintain the admissibility of the tree. Corrections are applied to cells with separate orders of `0, 0`.

### Lemma 2:  
Chain \( E \) of the admissible tree, where `0, 0` stands in the separate orders in every cell of this chain, is the **branch pivot** for the cell that directly precedes the first cell \( w \) of the chain.

**Proof:**  
By contradiction, assume this is incorrect. From the set of all chains beginning with \( w \), choose the chain with the most common cells with \( E \). If cell \( t \) is the last common cell, its branches would have different lengths, contradicting that `0, 0` can stand in the separate orders of cell \( t \). Hence, the lemma holds. \( \square \)

## Tree Reorganization Cases
There are three possible cases after inserting a new element:

1. If \( E \) is the entire recorded chain, the tree remains admissible.
2. If \( E \) lies on the short branch of cell \( s \), the tree becomes admissible after insertion.
3. If \( E \) lies on the long branch of cell \( s \), reorganization is required, as shown in Figure 3.

After reorganization, the tree becomes admissible, with the reference board structure corrected.

## Conclusion
The search requires \( \log_2(N - 1) \) operations. The movement along the recorded chain to cell \( s \) requires at most \( \log_2(N + 1) \) operations, and reorganization takes a constant number of operations. In total, the process requires \( O(\log_2(N + 1)) \) operations.

*Received 13/APR/62*

## Bibliography
1. P.F. Windley, *Comput. J.*, 3 (1960/61), 84.  
*Translated by Myron J. Ricci*

# 信息组织算法  
**G. M. Adel'son-Vel'skii 和 E. M. Landis**

在本文中，我们讨论了自动计算机中包含的信息的组织问题。研究将基于三地址机器。

## 问题的陈述  
信息从某个存储区按顺序进入机器。信息元素包含在一组依次排列的单元中。每个信息元素中都包含一个不同的数值（信息估计值）。信息必须以某种方式在机器的存储器中进行组织，以确保在任何时刻不需要进行大量操作来扫描具有给定估值的信息并记录新的信息元素。

我们提出了一种算法，其中搜索和记录均在 \( \log N \) 次操作内完成，\( N \) 是当前时刻已进入的信息元素的数量。机器存储器的一部分被划分出来用于存储输入的信息。这些信息元素按照它们的输入顺序排列。此外，在存储器的另一部分形成了一个**参考板**，其中每个单元对应一个信息元素。

参考板是一个**二叉树**（见图1a），其中每个单元最多有一个左子单元和一个右子单元。直接的隶属关系引入了部分排序。对于树中的每个单元，所有隶属于左（或右）直接隶属单元的单元都位于给定单元的左（或右）侧。此外，我们假设有一个**头节点**，所有其他单元都隶属于它。

通过传递性，"更左"和"更右"的概念扩展到所有单元对，整个结构因此变得有序。参考板中单元的排列应与对应信息元素的估计值排列一致（考虑到估计值从左到右递增）。

在参考板的每个单元的第一个地址中，指明了对应信息元素的位置。左、右直接隶属单元的地址分别位于第二和第三地址中。如果一个单元在左侧或右侧没有直接隶属单元，那么相应的地址中会记为零。头节点的地址存储在一个固定单元中。

## 树的结构与可接受性
我们称树的单元序列为**链**，其中每个前一个单元直接隶属于下一个。对于树的每个单元，我们将**左（右）分支的长度**定义为由隶属于给定单元且位于其左侧（右侧）的单元组成的链的最大长度。任何长度等于分支长度的链称为**分支支点**。

一个**可接受的树**是指每个单元的左分支长度与右分支长度的差异不超过一个单位（见图1b）。每个地址板单元包含有关分支长度的顺序。如果左分支比右分支长，顺序为`1, 0`；如果右分支比左分支长，顺序为`0, 1`；如果长度相等，顺序为`0, 0`。如果两侧都没有隶属单元，则该侧分支长度视为零。

![图 1](#)  
![图 2](#)

记录算法确保参考板在每一时刻都是一个可接受的树。

### 引理 1：  
设可接受树中的单元数量为 \( N \)，则最大分支长度不大于 \( \frac{3}{2} \log_2(N + 1) \)。

**证明：**  
设 \( N_n \) 为当分支的最大长度为 \( n \) 时可接受树中的最小单元数量。可以很容易证明：

\[
N_n = N_{n-1} + N_{n-2} + 1
\]

解出此方程，我们得到：

\[
N_n = \frac{(1 + \sqrt{5})^n}{2^n} - \frac{(1 - \sqrt{5})^n}{2^n} - 1
\]

因此，  
\[
n \leq \log_2(N + 1)
\]  
\( \square \)

## 搜索算法
给定估计值的信息元素的搜索算法如下：

1. 将给定估计值与对应于头节点的信息元素的估计值进行比较。
2. 根据比较结果，将给定估计值与头节点的左或右隶属单元对应的信息元素的估计值进行比较。
3. 在第 \( k \) 次比较后，若 \( m < m_i \)（或 \( m > m_i \）），则在第 \( k+1 \) 次比较时，将给定估计值与单元左侧（或右侧）隶属单元对应的信息元素进行比较。如果 \( m = m_i \)，则搜索完成。

由于操作次数与比较次数成正比，每次比较有三种可能的结果，由引理1可知，搜索所需的操作次数不超过 \( C \log_2(N) \)。

## 插入与树重组
接下来描述如何将参考板保持为可接受树的算法：

1. 当第一个信息元素进入时，它存储在某个单元中，该单元成为**头节点**。
2. 当新信息元素进入时，应用搜索算法找到新元素的适当位置。
3. 如果新元素已经存在，则树保持不变。否则，新的单元作为某个单元的直接隶属单元插入参考板中，插入到该单元的左侧或右侧。
4. 插入后，调整记录链中的分支长度，以保持树的可接受性。在单元的分支顺序为`0, 0`的情况下进行修正。

### 引理 2：  
在可接受树中，若链 \( E \) 的每个单元的分支顺序为`0, 0`，则该链是直接位于第一个单元 \( w \) 之前的单元的**分支支点**。

**证明：**  
假设该引理不成立。在所有以 \( w \) 开头的链中，选择与 \( E \) 具有最多相同单元的链。设最后一个相同单元为 \( t \)，其分支长度不同，因此在单元 \( t \) 的分支顺序中不可能为`0, 0`。因此，引理成立。 \( \square \)

## 树重组的情况
插入新元素后，可能出现三种情况：

1. 若 \( E \) 是整个记录的链，则树保持可接受。
2. 若 \( E \) 位于单元 \( s \) 的短分支上，则插入后树仍然可接受。
3. 若 \( E \) 位于单元 \( s \) 的长分支上，则需要进行重组，如图3所示。

重组后，树再次成为可接受树，并对参考板的结构进行修正。

## 结论
搜索操作需要 \( \log_2(N - 1) \) 次操作。沿记录链移动到单元 \( s \) 最多需要 \( \log_2(N + 1) \) 次操作，重组操作的次数是常量。因此，总共需要 \( O(\log_2(N + 1)) \) 次操作。

*接收日期：1962年4月13日*

## 参考文献
1. P.F. Windley, *Comput. J.*, 3 (1960/61), 84.  
*译者：Myron J. Ricci*
