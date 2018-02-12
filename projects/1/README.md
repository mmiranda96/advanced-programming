# 1072. Routing
Time limit: 1.0 second  
Memory limit: 64 MB

## Description
There is a TCP/IP net of several computers. It means that:
- Each computer has one or more net interfaces.
- Each interface is identified by its IP-address and a subnet mask — these are two four-byte numbers with a point after each byte. A subnet mask has a binary representation as follows: there are k 1-bits, then — m 0-bits, k+m=8*4=32 (e.g., 212.220.35.77 — is an IP-address and 255.255.255.128 — is a subnet mask).
- Two computers belong to the same subnet, if and only if (IP1 AND NetMask1) = (IP2 AND NetMask2), where IPi and NetMaski — are an IP-address and subnet mask of i-th computer, AND — is bitwise.
- A packet is transmitted between two computers of one subnet directly.
If two computers belong to different subnets, a packet is to be transmitted via some other computers. The packet can pass from one subnet to another only on computer that has both subnets interfaces.

Your task is to find the shortest way of a packet between two given computers.

## Input
The first line contains a number N — an amount of computers in the net, then go N sections, describing interfaces of each computer. There is a number K in the first line of a section — that is an amount of interfaces of the computer, then go K lines — descriptions of the interfaces, i.e. its IP-address and a subnet mask. The last line of an input contains two integers — the numbers of the computers that you are to find a way between them.
You may assume that 2 ≤ N ≤ 90 and K ≤ 5.

## Output
The word “Yes” if the route exists, then in the next line the computer numbers passed by the packet, separated with a space. The word “No” otherwise.

## Sample
### Input
```
6
2
10.0.0.1 255.0.0.0
192.168.0.1 255.255.255.0
1
10.0.0.2 255.0.0.0
3
192.168.0.2 255.255.255.0
212.220.31.1 255.255.255.0
212.220.35.1 255.255.255.0
1
212.220.31.2 255.255.255.0
2
212.220.35.2 255.255.255.0
195.38.54.65 255.255.255.224
1 
195.38.54.94 255.255.255.224
1 6
```
### Output
```
Yes
1 3 5 6
```
## Critical thinking
This problem is essentially finding a one-to-one path in a undirected, unweighted graph. We define each computer as a node. The edges will connect computers with at leas an interface in the same network. If a computer has multiple interfaces in the same network, only one will be taken. In the example case, computers are connected in the following way:
- Computer 1:
    - Connected to computer 2 in network 10.0.0.0/8
    - Connected to computer 3 in network 192.168.0.0/24
- Computer 2:
    - Connected to computer 1 in network 10.0.0.0/8
- Computer 3:
    - Connected to computer 1 in network 192.168.0.0/24
    - Connected to computer 4 in network 212.220.31.0/24
    - Connected to computer 5 in network 212.220.35.0/24
- Computer 4:
    - Connected to computer 3 in network 212.220.31.0/24
- Computer 5:
    - Connected to computer 4 in network 212.220.35.0/24
    - Connected to computer 6 in network 195.38.54.64/27
- Computer 6:
    - Connected to computer 5 in network 195.38.54.64/27

In a graph, this looks in the following way:  
[IMAGE]

Building this graph based on the input is O(n^2) in a naïve approach, since we need to check all the nodes for each node (to build edges). We can optimize this with the following algorithm:
```
/*
 * Build a hash table of (network, list<node>)
 */
ht := hashTable()
for n in nodes:
    for i in n.interfaces:
        if !ht.contains(i.network):
            ht.add(i.network)
        ht[i.network].add(n)

/*
 * For each node, find nodes in the same network and connect.
 */
for n in nodes:
    for i in n.interfaces:
        adj := ht[i.network]
        n.adj := adj

/*
 * Run a path finding algorithm, such as depth-first search or breath-first search.
 */
path := bfs()
```