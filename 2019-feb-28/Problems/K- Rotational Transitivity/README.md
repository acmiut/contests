## Rotational Transitivity

### Solution:

<div dir="rtl">
 ابتدا برای سادگی از همه‌ی شماره‌ها یکی کم می‌کنیم. فرض کنیم مقدار k ثابت باشد. تمامی مقادیر

 <a href="https://www.codecogs.com/eqnedit.php?latex=a.k(mod&space;n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?a.k(mod&space;n)" title="a.k(mod n)" /></a>
را برای همه‌ی a ها از 0 تا وقتی که دوباره به 0 برسیم محاسبه می‌کنیم. این مقدار را می‌توان به صورت
a.k – b.n
هم نوشت. طبق قضیه‌ی بزو معادله‌ی
a.k – b.n = c
جواب صحیح برای a و  b دارد اگر و تنها اگر
gcd(k, n) | c
 
به علاوه واضح است که تمامی مقادیر ممکن برای c قبل از صفر شدن دوباره‌ی عبارت، به دست خواهد آمد. بنابراین کافی‌ست مقادیری از k را در نظر بگیریم که n را عاد می‌کنند. پس همه‌ی مقسوم علیه‌های n را در 
<a href="https://www.codecogs.com/eqnedit.php?latex=O(n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(n)" title="O(n)" /></a>
 به دست آورده و برای هر کدام از آن‌ها در 
<a href="https://www.codecogs.com/eqnedit.php?latex=O(1)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" /></a>
مجموع سری حسابی ایجاد شده را پیدا می‌کنیم.        
</div>
