
N		100	1000	10000	100000


Metoda de sortare 1:

Bubble Sort	0.000000 secunde	0.003000 secunde	0.153000 secunde	24.729000 secunde

Metoda de sortare 2:

Quick Sort	0.000000 secunde	0.000000 secunde	0.001000 secunde	0.009000 secunde

În urma analizei empirice, se observă că algoritmul Bubble Sort are un timp de execuție care crește foarte rapid odată cu dimensiunea vectorului, devenind ineficient pentru valori mari ale lui N.
În schimb, Quick Sort rămâne foarte rapid chiar și pentru N = 100000, demonstrând eficiența sa superioară.
Această diferență se datorează complexității algoritmilor: O(n²) pentru Bubble Sort și O(n log n) pentru Quick Sort.




N	100	1000	10000	100000

Linear Search	0.117000	0.788000	6.689000	24.896000

Binary Search	0.072000	0.111000	0.132000	0.1381000


În urma analizei empirice, se observă că timpul de execuție pentru Linear Search crește semnificativ odată cu mărirea dimensiunii vectorului. Acest lucru se explică prin faptul că algoritmul verifică elementele succesiv, unul câte unul.
În schimb, Binary Search are un timp de execuție mult mai mic și crește foarte puțin chiar și pentru valori mari ale lui N, deoarece reduce spațiul de căutare la jumătate la fiecare pas.
Prin urmare, Binary Search este mult mai eficient decât Linear Search pentru tablouri mari.


N	            50	     100	     1000	   10000	   100000	   1000000

Fibonacci	0.000000	0.000000	0.000000	0.001000	0.046000	4.942000


În urma analizei empirice, se observă că timpul de execuție al algoritmului Fibonacci crește odată cu valoarea lui N, însă creșterea este relativ controlată datorită utilizării metodei iterative.
Utilizarea bibliotecii GMP permite lucrul cu numere foarte mari, evitând problema depășirii capacității tipurilor standard de date. Astfel, programul poate calcula valori Fibonacci chiar și pentru N foarte mare (de exemplu N = 1000000), unde metodele clasice ar eșua.
Pentru compilare și rulare este necesară utilizarea consolei, deoarece programul depinde de biblioteca GMP. Compilarea se realizează cu comanda gcc fibonacci.c -lgmp -o fibonacci.exe, iar execuția cu .\fibonacci.exe.



gcc fibonacci.c -lgmp -o fibonacci.exe
>> .\\fibonacci.exe         
