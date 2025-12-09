+++
title = "Structures de controle"
weight = 40
+++

Le contrôle du flux d'exécution est, lui aussi, un héritage du C, vous trouverez de nombreuses ressemblances avec le Java.

## Les conditions
Ici aussi, on suit la même syntaxe qu'en java pour les 2 instructions conditionnelles

### If
```C++
#include <iostream>
using namespace std;

int main(){
    int n = -8;

    if(n > 0){
        cout << "Positive";
    } else if(n < 0){
        cout << "Negative";
    }else{
        cout << "Zero";
    }

    return 0;
}
```

### Switch
```C++
#include <iostream>
using namespace std;

int main(){
  	
    // Variable to the used as switch expression
    char x = 'A';

    // Switch statement with three cases
    switch(x){
    case 'A':
        cout << "A";
        break;
    case 'B':
        cout << "B";
        break;
    default:
        cout << "Other than A and B";
        break;
    }
    return 0;
}
```


## Les boucles

On retrouve les formes habituelles de boucles en C++. Les boucles `for` lorsque l'on connait à l'avance le nombre d'itérations (par exemple parcourir un tableau), ou la boucle `while` quand on ne connait pas à l'avance le nombre d'itérations (par exemple valider une entrée utilisateur).

### For
Cette forme de boucle est identique à celle que vous avez rencontrée en Java.

```C++
for(int i = 5; i < 10; i++){
      	cout << "Hi" << endl;
    }
```

> [!warning] Attention
> Comme en Java, il faut faire attention à la valeur de votre index lorsque vous accédez à un tableau. Si votre index dépasse votre tableau, vous risquez de créer des bugs.

#### For sur un intervalle
Cette manière de faire une boucle a été introduite avec C++11, elle s'inspire des langages plus récents, comme le python.


```C++
#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
  	
    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}
```

Résultat :
```
10 20 30 40 50
```

Ici, on donne une variable (`val`) et un tableau (`arr`). À chaque itération, `val` va prendre la valeur correspondante dans le tableau. 

L'avantage de cette forme de boucle, c'est qu'on reste toujours à l'intérieur du tableau, on évite les bugs de dépassement d'index.

### While

Les 2 versions de boucle `while` existe aussi en C++ :

```C++
int i = 0;
while(i < 5){
cout << "Hi" << endl;
        i++;
}
```

```C++
int i = 0;
do{
    cout << "Hi" << endl;
    i++;
} while(i < 5);
```

> [!note]
> Faites attention à bien modifier votre condition de sortie dans le corps de votre boucle. Autrement, vous risquez de vous retrouver dans une boucle infinie.

### Boucles infinies

```C++
for(;;){
    // corps de la boucle
}
```

```C++
while(true){
    // corps de la boucle
}
```


## Les sauts

### break / continue
Exemple de l'instruction `continue`:

```C++
#include <iostream>
using namespace std;

int main(){
    for(int i = 1; i < 10; i++){

      	// Skip the execution for i = 5
        if (i == 5){
            continue;
        }
        cout << i << " ";
    }
    return 0;
}
```
{{% expand title="Affichage :" %}} 
```
1 2 3 4 6 7 8 9 
```
{{% /expand %}}

Exemple de l'instruction `break`:
```C++
#include <iostream>
using namespace std;

int main(){
  
  	// Loop to print digits from 1 to 4
    for(int i = 1; i < 10; i++){

        // Breaking Condition
        if(i == 5){
            break;
        }
        cout << i << " ";
    }
  
    return 0;
}
```
{{% expand title="Affichage :" %}} 
```
1 2 3 4
```
{{% /expand %}}

### goto
Exemple :
```C++
#include <iostream>
using namespace std;

int main(){
    int n = 4;

    if(n % 2 == 0){
      
      	// Skipping to label1
        goto label1;
    }else{
      	// Skipping to label2
        goto label2;
    }

label1:
    cout << "Even" << endl;
    return 0;

label2:
    cout << "Odd" << endl;
	return 0;
label3:
	cout << "Unspecified";
	return 0;
}
```

## Sources
- https://www.geeksforgeeks.org/cpp/range-based-loop-c/