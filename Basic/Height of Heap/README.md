<h2><a href="https://www.geeksforgeeks.org/problems/height-of-heap5025/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Height of Heap</a></h2><h3>Difficulty Level : Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Heap of size <strong>N </strong>in an array <strong>arr[]</strong>.&nbsp;Write a program to calculate the height of the Heap.<br><br><strong>Note:&nbsp;</strong>Return 1 if the N is 1.<br></span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> N = 6
arr = {1, 3, 6, 5, 9, 8}
<strong>Output:</strong> 2
<strong>Explaination:</strong> The tree is like the following</span>
           <span style="font-size: 18px;">(1)
       /   \
    (3)    (6)
    / \     /
  (5) (9) (8)</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> N = 9
arr = {3, 6, 9, 2, 15, 10, 14, 5, 12}
<strong>Output:</strong> 3
<strong>Explaination:</strong> The tree looks like following</span>
               <span style="font-size: 18px;">(2)
        /      \
      (3)      (9)
     /  \     /   \
   (5) (15) (10) (14)
   / \
 (6) (12)</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>heapHeight()</strong> which takes the value N and the array arr as input parameters and returns the height of the heap.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(logN)<br><strong>Expected Auxiliary Space:</strong> O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>4</sup><br>1&nbsp;≤ arr[i]&nbsp;≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Heap</code>&nbsp;<code>Data Structures</code>&nbsp;