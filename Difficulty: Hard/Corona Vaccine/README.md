<h2><a href="https://www.geeksforgeeks.org/problems/corona-vaccine--141631/1">Corona Vaccine</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Geek has successfully developed an effective vaccine for the Coronavirus and aims to ensure that every house in Geek Land has access to it. The houses in Geek Land are structured as a <strong>binary tree</strong>, where each node represents a house, and the edges denote direct connections between houses.</span></p>
<p><span style="font-size: 18px;">Each house that receives a <strong>vaccine kit</strong> can provide coverage to:</span></p>
<ul>
<li><span style="font-size: 18px;">Itself</span></li>
<li><span style="font-size: 18px;">Its direct parent house (if it exists)</span></li>
<li><span style="font-size: 18px;">Its immediate child houses (if any exist)</span></li>
</ul>
<p><span style="font-size: 18px;">Your task is to determine the minimum number of houses that must be supplied with a vaccine kit to ensure that every house is covered.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [1, 2, 3, N, N, N, 4, N, 5, N, 6]<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/886892/Web/Other/blobid0_1739010580.png" alt="" width="400" height="356"></span>

<span style="font-size: 18px;"><strong>Output: </strong>2
<strong>Explanation: </strong>The vaccine kits should be supplied to house numbers 1 and 5.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root = [1, 2, 3]<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/886892/Web/Other/blobid1_1739010580.png" alt="" width="337" height="308"></span>
<span style="font-size: 18px;"><strong>Output: </strong>1
<strong>Explanation: </strong>The vaccine kits should be supplied to house number 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 10<sup>5</sup></span></p>
<p><span style="font-size: 18px;">1 ≤&nbsp; node-&gt;data&nbsp; ≤&nbsp;</span><span style="font-size: 18px;">10</span><sup>5</sup></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;