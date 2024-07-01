<h2><a href="https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1">Largest square formed in a matrix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary matrix <strong>mat</strong>&nbsp;of size <strong>n</strong> * <strong>m</strong>, find out the maximum length of a side of square sub-matrix with all 1s.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, m = 2
mat = {{1, 1}, 
&nbsp;      {1, 1}}
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, m = 2
mat = {{0, 0}, 
&nbsp;      {0, 0}}
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no 1 in the matrix.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>maxSquare()</strong> which takes 2 integers <strong>n</strong>, <strong>m</strong> and a 2-d integer array <strong>mat</strong> as input parameters and returns the maximum length of a side of square sub-matrix with all 1s.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n*m)<br><strong>Expected Auxiliary Space:</strong> O(n*m)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 100<br>0 ≤ mat[i][j] ≤ 1&nbsp;</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Arrays</code>&nbsp;