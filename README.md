## Навигация   
[1. Краткое описание](#Description)  
[2. Описание алгоритма](#Algorithm)  
[3. Модульное тестирование](#UnitTests)  
[3.1 Тестирование методом черного ящика](#BlackTests)  
[3.2 Тестирование методом белого ящика](#WhiteTests)  
[3.3 Результаты тестирования и оценка покрытия кода тестами](#TestingAndCoverage)  
[4. Сборка](#Build)  
[5. Руководство пользователя](#UsersManual)  
[6. Пример](#Example)  
  
<a name="Description"><h2>Краткое описание</h2></a>
Консольное приложение было реализовано на языке C++ в среде Microsoft Visual Studio 2019 с использованием библиотеки OpenGL (для визуализации результатов).  
Приложение выполняет поиск точек пересечения двух треугольников в 2D-пространстве.
Пользователь вводит 6 вершин (точек) треугольников в консоли (У координат есть ограничения: числа x и y находятся в диапазоне от -300 до 300). На консоли отображается информация о вершинах треугольников и результат пересечения в виде определенного сообщения и точек, в которых пересекаются объекты. Полученная информация визуализируется в всплывающем окне.  
  
Работоспособность исходного кода программы проверяется посредством модульных тестов методами черного и белого ящика. Тестирование было выполнено с использованием модуля CppUnit (Проект машинного модульного теста в MSVS). Оценка покрытия кода тестами была исполнена с помощью плагина [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage).
<a name="Algorithm"><h2>Описание алгоритма</h2></a>
Алгоритм нахождения точек пересечения двух треугольников:  
```C++
TriangleIntersectionContour(Polygon &PolygonPoints, Triangle Figure1, Triangle Figure2);
```
На вход подаются переменные: PolygonPoints, в которую будут записываться найденные точки пересечения; Figure1 – содержатся вершины треугольника 1; Figure2 – вершины треугольника 2.  
<a name="Num1"></a>
1. Находятся уравнения прямых каждой из сторон треугольников по заданным точкам
```C++
LinesTriangle(vector<LineEquation>& LinesFigure, Triangle Figure);
```
LinesFigure – вектор, в который будут записываться уравнения прямых каждой из сторон треугольника. Figure – треугольник.  
Уравнения прямых составляются по двум точкам, составляющих сторону треугольника. Уравнение прямой имеет вид:  

> ![equation](https://latex.codecogs.com/svg.image?(y_1-&space;y_2)x&plus;(x_2-x_1)y&plus;(x_1&space;y_2-x_2&space;y_1)=0=>&space;Ax&plus;By&plus;C=0), где:  
> ![equation](https://latex.codecogs.com/svg.image?(x_1,&space;y_1)) – координата первой точки, ![equation](https://latex.codecogs.com/svg.image?(x_2,&space;y_2)) – координата второй точки. 
   
Каждая линия будет хранить в себе параметр A, B и С. А также первую и вторую точки линии, т.к. они потребуются для определения положения точки на плоскости относительно отрезка, заданного этими точками.  
Поскольку задавать точки можно в произвольном порядке, то необходимо их расставить на “свои места”. Таким образом, если:  
* Первая точка меньше второй по координате X, то точки не меняются;
* Первая точка равна второй по координате X. Смотрим тогда по оси Y. Если первая точка меньше второй, то точки не меняются, иначе – первая точка принимает координаты второй, а вторая координаты первой;
* Первая точка больше второй по координате X, то точки меняются. Первая = Вторая, а Вторая = Первая.  
  
Эти значения точек потребуются в дальнейшем для проверки полученной точки пересечения (Принадлежит ли она отрезку или нет).  
  
  2. Выполняется поиск точек внутри треугольника
```C++
SearchPointInTriangle(Polygon& PolygonPoints, vector<LineEquation> LinesFigure1, Triangle Figure2);
```
PolygonPoints – переменная для хранения найденных точек; LinesFigure1 – линии треугольника 1; Figure2 – треугольник 2.  
В каждое уравнение прямой сторон треугольника 1 необходимо подставить каждую вершину треугольника 2. Это положение можно записать в виде системы уравнений:  
  
> ![equation](https://latex.codecogs.com/svg.image?%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20A_1x&plus;B_1y&plus;C_1=0%20%5C%5C%20A_2x&plus;B_2y&plus;C_2=0%20%5C%5C%20A_3x&plus;B_3y&plus;C_3=0%20%5C%5C%5Cend%7Bmatrix%7D%5Cright.%20)  
  
Положение точки вычисляется в зависимости от выполнения следующих условий:  
* Если значение каждого из уравнений прямых > 0, то точка треугольника 2 располагается внутри треугольника 1;
* Если значение каждого из уравнений прямых < 0, то точка треугольника 2 располагается внутри треугольника 1;
* В остальных случаях – точка располагается снаружи или на прямой, если значение хотя бы одного из уравнений = 0.  
  
Далее, необходимо выполнить проверку на то, сколько у нас нашлось точек. Если нашлось три точки, то это значит, что один треугольник располагается во втором. Если ноль, то необходимо рассматривать следующий треугольник и выполнить те же самые проверки.  
  
  3.	Поиск точек пересечения треугольника
```C++
IntersectionOfLines(Polygon& PolygonPoints, LineEquation Eq1, LineEquation Eq2);
```
PolygonPoints – переменная для хранения найденных точек; Eq1 – уравнение прямой треугольника 1; Eq2 – уравнение прямой треугольника 1.  
Для каждой прямой треугольника 1 будет искаться возможное пересечение с каждой прямой треугольника 2.  
Итак, для того, чтобы определить точку пересечения прямых на плоскости, необходимо решить систему линейных уравнений, состоящую из уравнений этих прямых.  
  
> ![equation](https://latex.codecogs.com/svg.image?%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20A_1x&plus;B_1y&plus;C_1=0%20%5C%5C%20A_2x&plus;B_2y&plus;C_2=0%20%5C%5C%5Cend%7Bmatrix%7D%5Cright.%20), где:  
> Координата (x,y) является точкой пересечения прямых, т.е. принадлежит данным уравнениям прямых.  
  
Данная СЛАУ может быть решена [методом Крамера](https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%9A%D1%80%D0%B0%D0%BC%D0%B5%D1%80%D0%B0). Этот метод основан на поиске ненулевого определителя.  
Тогда, следует переписать наше СЛАУ в виде:  

> ![equation](https://latex.codecogs.com/svg.image?%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20A_1x&plus;B_1y=-C_1%20%5C%5C%20A_2x&plus;B_2y=-C_2%20%5C%5C%5Cend%7Bmatrix%7D%5Cright.%20)  
  
Далее необходимо найти три определителя – ![equation](https://latex.codecogs.com/svg.image?D,&space;D_x,&space;D_y&space;). Которые потребуются для расчета координат х и у.  

> ![equation](https://latex.codecogs.com/svg.image?D=%20%5Cbegin%7Bvmatrix%7D%20A_1&B_1%20%20%5C%5C%20A_2&B_2%20%20%5C%5C%5Cend%7Bvmatrix%7D=A_1*B_2-%20B_1*A_2%20)
  
Если на этапе вычисления общего определителя D выясняется, что он = 0, то это означает, что данные линии треугольников не пересекаются и дальнейшие вычисления не производятся.  
Иначе,  
  
> ![equation](https://latex.codecogs.com/svg.image?D_x=%20%5Cbegin%7Bvmatrix%7D%20-C_1&B_1%20%20%5C%5C%20-C_2&B_2%20%20%5C%5C%5Cend%7Bvmatrix%7D=-C_1*B_2-B_1*(-C_2)%20) - определитель для координаты x;  
> ![equation](https://latex.codecogs.com/svg.image?D_y=%20%5Cbegin%7Bvmatrix%7D%20A_1&-C_1%20%20%5C%5C%20A_2&-C_2%20%20%5C%5C%5Cend%7Bvmatrix%7D=A_1*(-C_2)-(-C_1)*A_2%20) - определитель для координаты y.  
  
Координаты x и y находятся следующим образом:  
  
> ![equation](https://latex.codecogs.com/svg.image?x=%5Cfrac%7BD_x%7D%7BD%7D=%5Cfrac%7B-C_1*B_2-%20B_1*(-C_2)%7D%7BA_1*B_2-%20B_1*A_2%7D%20)  
> ![equation](https://latex.codecogs.com/svg.image?y=%5Cfrac%7BD_y%7D%7BD%7D=%5Cfrac%7BA_1*(-C_2)-(-C_1)*A_2%7D%7BA_1*B_2-%20B_1*A_2%7D%20)  
  
  
   3.1  Необходимо определить положение найденной точки  

Ясное дело, что найденная точка принадлежит прямой. Но, поскольку, сама прямая является бесконечной, то не факт, что данная точка будет принадлежать двум сторонам треугольников, т.к. точка пересечения прямых может быть где-то далеко за пределами этих треугольников. Поэтому, перед тем, как сохранить найденную точку, необходимо выполнить проверку на ее положение.  
Теперь нам потребуются точки, которые мы сохраняли для прямых [в пункте 1](#Num1). Будем сопоставлять найденные точки, относительно отрезков (первая-вторая точка).  
Для определения положения точки были определены следующие правила:  
* По координате х. Если найденная точка *меньше первой или больше второй точки 1-ого уравнения прямой* или *меньше первой или больше второй точки 2-ого уравнения прямой*, то точка располагается сзади или спереди отрезков;
* По координате х. Если найденная точка *равна первой и второй точке 1-ого уравнения прямой*, то это вертикальная линия. Тогда смотрим по координате Y. Если найденная точка *меньше первой или больше второй точки 1-ого уравнения прямой*, то точка располагается ниже или выше отрезков;
* По координате х. Если найденная точка *равна первой и второй точке 2-ого уравнения прямой*, то это вертикальная линия. Тогда смотрим по координате Y. Если найденная точка *меньше первой или больше второй точки 2-ого уравнения прямой*, то точка располагается ниже или выше отрезков;
* Если найденная точка *равна одной из вершин*, то необходимо проверить была ли она добавлена раннее на одном из этапов поиска (Это значит, что треугольники соприкасаются и эту точку образуют больше двух линий);
* В остальных случаях выполняется сохранение точки.


<a name="UnitTests"><h2>Модульное тестирование</h2></a>
<a name="BlackTests"><h2>Тестирование методом черного ящика</h2></a>
[Тестирование методом черного ящика](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%BF%D0%BE_%D1%81%D1%82%D1%80%D0%B0%D1%82%D0%B5%D0%B3%D0%B8%D0%B8_%D1%87%D1%91%D1%80%D0%BD%D0%BE%D0%B3%D0%BE_%D1%8F%D1%89%D0%B8%D0%BA%D0%B0) подразумевает под собой, что исходный код не известен. И тесты составляются, полагаясь на спецификацию и технические требования.  
Исходя из поставленной задачи (разработка алгоритма поиска точек пересечения двух треугольников в 2d-пространстве), можно выделить следующие варианты проверок для тестирования методом черного ящика:  
* Два треугольника не пересекаются;
* Два треугольника имеют 1 точку пересечения (соприкасаются);
* Два треугольника имеют 2 точки пересечения (соприкасаются);
* Два треугольника имеют 3 точки пересечения;
* Два треугольника имеют 4 точки пересечения;
* Два треугольника имеют 5 точек пересечения;
* Два треугольника имеют 6 точек пересечения;
* Проверка на значимость положения вершин треугольника. Т.е., что будет, если вершины треугольника поменять местами. Будет ли результат идентичен;
* Координаты треугольников находятся в одной точке (Ввод 6 одинаковых точек);
* Координаты одного из треугольников образуют линию (т.е. будет ли приниматься такое, что три точки образуют не треугольник и с этими данными определяться точки пересечения);
  
ССЫЛКА НА СПЕЦИФИКАЦИЮ  
  
<a name="WhiteTests"><h2>Тестирование методом белого ящика</h2></a>
В [тестировании методом белого ящика](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%B1%D0%B5%D0%BB%D0%BE%D0%B3%D0%BE_%D1%8F%D1%89%D0%B8%D0%BA%D0%B0) предполагается, что исходный код программы известен. По этому методу следует проверить все ветви программы.  
Исходя из выше сказанного, можно предложить следующие варианты проверок для тестирования методом белого ящика:  
1.  Тестирование метода *TriangleIntersectionContour* (поиск точек пересечения треугольников):  
* Треугольник 2 в треугольнике 1;
* Имеются точки треугольника 2 внутри треугольника 1 (1-2 точки);
* Треугольник 1 в треугольнике 2;
* В треугольнике 1 не было найдено точек. В треугольнике 2 были найдены точки (1-2 точки).
2.	Тестирование метода *SearchPointInTriangle* (поиск точек внутри треугольника):  
* Внутри треугольника есть точки;
* Внутри треугольника точек нет.
3.	Тестирование метода *IntersectionOfLines* (поиск точки пересечения линий):  
* Линии не пересекаются;
* Линии пересекаются. Точка пересечения прямых располагается за пределами треугольников относительно оси Х (Если посмотреть на координатную плоскость, то слева или справа от объектов, сравнивая значения точки пересечения и точек отрезков на рассматриваемых линиях по оси Х);
* Линии пересекаются. Линия 1 – вертикальная линия. Точка пересечения располагается выше или ниже отрезка линии 1 относительно оси Y;
* Линии пересекаются. Линия 2 – вертикальная линия. Точка пересечения располагается выше или ниже отрезка линии 2 относительно оси Y;
* Линии пересекаются. Точка пересечения - точка соприкосновения двух отрезков (Начальная/конечная точка отрезка лежит на другом отрезке);
* Линии пересекаются. У отрезков имеется одинаковая точка начала/конца;
* Линии пересекаются. У отрезков имеется одинаковая точка начала/конца, но она была добавлена ранее (Ситуация, когда имеется общая вершина. Такую вершину пересекают 4 линии от двух треугольников).
4.  Тестирование метода *IsIdenticalTriangles* (проверка на идентичность треугольников):  
* Два треугольника совпадают;
* Два треугольника не совпадают.

ССЫЛКА НА СПЕЦИФИКАЦИЮ

<a name="TestingAndCoverage"><h2>Результаты тестирования и оценка покрытия кода тестами</h2></a>
**Результаты тестирования методом черного ящика**  
  
<img src="https://github.com/1i10/Intersection-points-of-two-triangles/blob/master/ExampleImages/%D0%A2%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5%D0%A7%D0%B5%D1%80%D0%BD%D1%8B%D0%BC%D0%AF%D1%89%D0%B8%D0%BA%D0%BE%D0%BC.png" width="700" height="300" />   

**Результаты тестирования методом белого ящика**  
  
<img src="https://github.com/1i10/Intersection-points-of-two-triangles/blob/master/ExampleImages/%D0%A2%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5%D0%91%D0%B5%D0%BB%D1%8B%D0%BC%D0%AF%D1%89%D0%B8%D0%BA%D0%BE%D0%BC.png" width="700" height="350" />  

**Оценка покрытия кода тестами методом черного ящика**  
  
<img src="https://github.com/1i10/Intersection-points-of-two-triangles/blob/master/ExampleImages/%D0%9F%D0%BE%D0%BA%D1%80%D1%8B%D1%82%D0%B8%D0%B5%D0%A7%D0%B5%D1%80%D0%BD%D1%8B%D0%BC.png" width="700" height="70" />  

**Оценка покрытия кода тестами методом белого ящика**  
  
<img src="https://github.com/1i10/Intersection-points-of-two-triangles/blob/master/ExampleImages/%D0%9F%D0%BE%D0%BA%D1%80%D1%8B%D1%82%D0%B8%D0%B5%D0%91%D0%B5%D0%BB%D1%8B%D0%BC.png" width="700" height="70" />  

**Оценка общего покрытия кода тестами**  
  
<img src="https://github.com/1i10/Intersection-points-of-two-triangles/blob/master/ExampleImages/%D0%9E%D0%B1%D1%89%D0%B5%D0%B5%D0%9F%D0%BE%D0%BA%D1%80%D1%8B%D1%82%D0%B8%D0%B5.png" width="700" height="70" />  
<a name="Build"><h2>Сборка</h2></a>
<a name="UsersManual"><h2>Руководство пользователя</h2></a>
<a name="Example"><h2>Пример</h2></a>
