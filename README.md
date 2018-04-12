# Homework1 - ROS

* [Getting started](#getting-started)
* [Prerequisiti](#prerequisiti)
* [Installazione](#installazione)
* [Avvio del progetto](#avvio-del-progetto)
* [Modo tradizionale](#modo-tradizionale)
* [Uso del launch file](#uso-del-launch-file)
* [Scelte implementative](#scelte-implementative)
* [Struttura del messaggio](#struttura-del-messaggio)
* [Elenco opzioni utente](#elenco-opzioni-utente)
* [Realizzato con](#realizzato-con)
* [Autore](#autore)
* [Licenza](#licenza)

Primo compito del corso laboratorio Ciberfisico. 

![laboratorio ciberfisico](images/cyberphysical-lab.jpg)

## Getting started

Clonare tramite il comando "git clone" il repository h1_id778tlx caricato sul portale git hub, nella directory home_catkin/src (al posto di home_catkin scrivere la propria home directory di ROS) 

```
git clone https://github.com/davemol/h1_id778tlx.git
```

### Prerequisiti

Necessario avere catkin ROS installato sul proprio pc. É inoltre consigliata l'ultima versione stabile di Ubuntu Linux (16.04 LTS)

### Installazione

* Spostarsi nella propria cartella home di ROS:

```
cd catkin_ws
```

* Eseguire il seguente comando:

```
catkin_make --pkg h1_id778tlx
```

## Avvio del progetto
 
Possono essere utilizzati 2 modi.

### Modo tradizionale

* Eseguire il nodo principale:

```
roscore
```

* Eseguire il nodo "talker":

```
rosrun h1_id778tlx t_user_info
```

* Eseguire il nodo "listener":

```
rosrun h1_id778tlx l_user_info
```

* Eseguire il nodo che legge da tastiera:

```
rosrun h1_id778tlx key_user_info
```

### Uso del launch file:

```
roslaunch h1_id778tlx h1_id778tlx.launch
```
![rqt_graph](images/run1.png)

![rqt_graph](images/run2.png)

## Scelte implementative

Il progetto crea i 3 nodi seguenti:

* **Nodo t_user_info:** nodo che si impegna di pubblicare ogni secondo sul topic "user_info" il messaggio - [t_user_info.cpp](src/t_user_info.cpp)

* **Nodo l_user_info:** nodo che si iscrive al topic "user_info" per ricevere i messaggi pubblicati e al topic "car_choice"
		    per conoscere la scelta dell'utente. Visualizza il contenuto del messaggio nella sua interezza o dopo averlo 			    opportunamente filtrato in base alla scelta dell'utente - [l_user_info.cpp](src/l_user_info.cpp)

* **Nodo key_user_info:** nodo che si impegna di leggere da tastiera le scelte dell' utente e di pubblicarle sul topic
		      "car_choice" - [key_user_info.cpp](src/key_user_info.cpp)

![rqt_graph](images/h1_id778tlx_rqtgraph.png)

### Struttura del messaggio

La struttura del messaggio pubblicato sul topic "user_info" è descritta in un file apposito [User_info.msg](msg/User_info.msg).

### Elenco opzioni utente

Le scelte dell'utente sono:

* a: visualizza tutto (età,nome,corso di studi)
* e: visualizza età
* c: visualizza corso di studi
* n: visualizza nome

## Realizzato con

* [ROS](http://wiki.ros.org/catkin) - framework utilizzato

## Autore

* **Davide Molinari** - *pagina git ufficiale* - [davemol](https://github.com/davemol)

## Licenza

Questo progetto ha la seguente licenza - vedi il [LICENSE](LICENSE) file per i dettagli

