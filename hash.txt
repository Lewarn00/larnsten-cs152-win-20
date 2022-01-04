//Lewis Arnsten
//CNet: larnsten
//lab: 5:00pm

//Question 1
int hash (char *string){
	unsigned long res = 17;

    for(int i = 0; string[i] != '\0'; i++){
    	int ascii = (int) string[i];
        res = 37 * res + ascii;
    }

    return hash;
}

//Question 2

for(i=0;i<n;i*=2)
   for(j=0;j<m;j++)
	do something;
//Complexity: O(n*log(n))

for(i=0;i<n;i++)
   for(j=0;j<i;j++)
	do something;
//Complexity: O(n^2)

int recursiveFun1(int n)
{
	if (n <= 0)
		return 1;
	else
		return 1 + recursiveFun1(n/5);
}
//Complexity: O(log(n)) base 5