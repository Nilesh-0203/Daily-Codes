<h2><a href="https://www.geeksforgeeks.org/problems/group-shifted-string/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Group Shifted String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18.6667px;">Given an array of strings (all lowercase letters), the task is to group them in such a way that all strings in a group are shifted versions of each other.</span></p>
<p><span style="font-size: 18.6667px;"> Two strings s1 and s2 are called shifted if the following conditions are satisfied:</span></p>
<ul>
<li><span style="font-size: 18.6667px;">s1.length = s2.length</span></li>
<li>s1[i] = s2[i] + m for <span style="font-size: 18.6667px;">1 &lt;= i &lt;= s1.length&nbsp; for a <strong>constant </strong>integer m</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Examples :<br></strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">arr = ["acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"]
</span><strong style="font-size: 14pt;">Output:</strong><span style="font-size: 14pt;"> [["acd", "dfg", "wyz", "yab", "mop"], ["bdfh", "moqs"], ["a", "x"]] 
</span><strong style="font-size: 14pt;">Explanation: </strong>All shifted strings are grouped together.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr = ["geek", "for", "geeks"]
<strong>Output: </strong>[["for"], ["geek"], ["geeks"]]<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr = ["aaa", "adb", "bbd", "dbc", "bca"]
<strong>Output: </strong>[["aaa"], ["adb"], ["bbd"], ["bca"], ["dbc"]]</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5</sup><br>1 ≤ arr[i].size() ≤ 5</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Hash</code>&nbsp;<code>Algorithms</code>&nbsp;