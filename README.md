# Binary treee of films Lab8v16
# To run
```
g++ main.cpp -o bTreeOfFilms
./bTreeOfFilms
```
# Film ~ struct Node (name,gerne,studio,duration), 

### Insert by name of film, 
```
    Btree b;
    b.insert("ARCADE","Adventure","Holy",2.23);
```
### delete by studio,
```
    b.deleteElemnt("Holy");
```
### print btree,
```
    b.print();
```
### print films by gerne.
```
b.searchByGerne("Adventure");
```
### Task
вставка вузла за назвою;
вилучення всіх фільмів вказаної студії;
вивід всіх фільмів вказаного жанру

