<h2><a href="https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Sum of Middle Elements of two sorted arrays</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given 2 sorted arrays <strong>Ar1</strong> and <strong>Ar2</strong> of size <strong>N</strong> each. Merge the given arrays and find the sum of the two middle elements&nbsp;of the merged array.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
Ar1[] = {1, 2, 4, 6, 10}
Ar2[] = {4, 5, 6, 9, 12}
<strong>Output:</strong> 11
<strong>Explanation:</strong> The merged array looks like
{1,2,4,4,<strong>5,6,</strong>6,9,10,12}. Sum of middle
elements is 11 (5 + 6).
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
Ar1[] = {1, 12, 15, 26, 38}
Ar2[] = {2, 13, 17, 30, 45}
<strong>Output:</strong> 32
<strong>Explanation:</strong>&nbsp;The merged array looks like
{1, 2, 12, 13, 1<strong>5, 17,</strong> 26, 30, 38, 45} 
sum of middle elements is 32 (15 + 17).</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findMidSum()</strong>&nbsp;which takes&nbsp;&nbsp;<strong>ar1, ar2</strong>&nbsp;and&nbsp;<strong>n&nbsp;</strong>as input parameters and returns the sum of middle elements.&nbsp;</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(log N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>3</sup><br>
1 &lt;= Ar1[i] &lt;= 10<sup>6</sup><br>
1 &lt;= Ar2[i] &lt;= 10<sup>6</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Divide and Conquer</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;