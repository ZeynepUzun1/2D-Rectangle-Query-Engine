## 📌 2D-Rectangle-Query-Engine

A C++ spatial indexing system designed to store axis-aligned rectangles and efficiently determine which rectangles contain a given point.

This project demonstrates geometric search techniques and hierarchical spatial partitioning to improve query performance over naive linear scanning.

---

## Overview

The **2D-Rectangle-Query-Engine** organizes rectangular regions using a custom two-dimensional tree structure. This enables efficient point queries by limiting the search to relevant spatial partitions instead of checking every rectangle.

Such spatial indexing techniques are widely used in graphics engines, GIS systems, collision detection, and spatial databases.

---

## Features

✔ Stores axis-aligned rectangles
✔ Efficient point-in-rectangle queries
✔ Custom 2D spatial tree structure
✔ Linked node storage for rectangles
✔ Modular object-oriented implementation
✔ Avoids brute-force search

---

## How It Works

### Spatial Partitioning

Rectangles are stored inside a hierarchical tree that subdivides 2D space into regions.

### Node Organization

Each node:

* represents a spatial region
* stores rectangles overlapping that region
* connects to child nodes for finer partitioning

### Query Process

When querying a point:

1. The tree is traversed according to spatial position.
2. Only relevant nodes are visited.
3. Rectangles in those nodes are checked.
4. Matching rectangles are returned.

This significantly reduces unnecessary checks.

---

## Project Structure

```
main.cpp
Rectangle.h / Rectangle.cpp
TwoDimTree.h / TwoDimTree.cpp
TwoDimTreeNode.h / TwoDimTreeNode.cpp
LinkedList.h
```

### Components

**Rectangle**

* Defines rectangle geometry
* Performs containment checks

**TwoDimTree**

* Manages spatial indexing
* Handles insertion & queries

**TwoDimTreeNode**

* Represents spatial partitions
* Stores rectangle references

**LinkedList**

* Stores rectangles within nodes

---

## ▶️ Example Usage

### Insert Rectangles

```cpp
Rectangle r1(0, 0, 10, 10);
Rectangle r2(5, 5, 15, 15);

tree.insert(r1);
tree.insert(r2);
```

### Query a Point

```cpp
tree.search(7, 7);
```

### Output

```
Point (7,7) is inside:
Rectangle 1
Rectangle 2
```

---

## ⏱ Complexity

| Operation         | Average Complexity |
| ----------------- | ------------------ |
| Insert            | O(log n)           |
| Query             | O(log n + k)       |
| Brute-force query | O(n)               |

*k = number of matching rectangles*
