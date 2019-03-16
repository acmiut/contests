## Colorful Blockchain

### Solution:

The problem is about counting the number of some combinatoric objects. Thus, dynamic programming is always the answer.

Let dp[i][j][mask] be the number of beautiful bicolorings of the first i columns such that j components are already created and can't be modified and the colors of the i-th column are determined by mask (its first bit is the color of the lower cell and its second bit the color of the upper cell). Component can be modified if the cell from the i-th column belongs to it.

The initial states are dp[0][0][mask]=1 for each mask=0..3 and dp[i][j][mask]=0 for any other state.

You should iterate over the possible nmask for the next column and recalculate the number of components. You can easily show that the current number of components and the last column is actually enough to get the new number of components.

We have some function get(mask,nmask) to determine the added number of components while transitioning from mask to nmask. These are just the couple of cases to handle carefully.

Then all the transitions are:

dp[i+1][j+get(mask,nmask)][nmask] += dp[i][j][mask].

However, the last column won't contain the answer as it is, the number of components will be incorrect. Let's add some dummy column n+1 equal to mask⊕3 for each mask. This will add all the real component to the total number. So the answer is the sum of dp[n][k−get(mask,mask⊕3)][mask] over all mask=0..3.

Overall complexity: O(n2⋅4m), where m is the number of rows (2 for this problem).
