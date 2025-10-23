#include "collisionTable.hpp"
#include "graph.hpp"
#include "building/building.hpp"
#include "lot.hpp"
#include "main.hpp"
#include "pool.hpp"

#include "spdlog/spdlog.h"

// External declarations for global pools
extern Pool<Node>* splitNodes;
extern Pool<Edge>* edges;
extern Pool<Lot>* lots;

void rebuildCollisionTablesFull() {
  SPDLOG_INFO("Rebuilding collision tables...");
  
  // Clear existing collision tables
  resetCollisionTables();
  
  // Reinitialize collision tables
  initCollisionTables();
  
  // Rebuild graph collisions
  SPDLOG_INFO("Rebuilding graph collisions...");
  int graphElementsAdded = 0;
  
  // Add all existing nodes to collision table
  for (int i = 1; i <= splitNodes->size(); i++) {
    Node* node = getNode(-i);
    if (node->flags & _graphExists) {
      addToCollisionTable(GraphCollisions, getGraphBox(-i), -i);
      graphElementsAdded++;
    }
  }
  
  // Add all existing edges to collision table
  for (int i = 1; i <= edges->size(); i++) {
    Edge* edge = getEdge(i);
    if (edge->flags & _graphExists) {
      addToCollisionTable(GraphCollisions, getGraphBox(i), i);
      graphElementsAdded++;
    }
  }
  
  SPDLOG_INFO("Added {} graph elements to collision table", graphElementsAdded);
  
  // Rebuild building collisions
  SPDLOG_INFO("Rebuilding building collisions...");
  int buildingsAdded = 0;
  for (int i = 1; i <= sizeBuildings(); i++) {
    Building* building = getBuilding(i);
    if (building->flags & _buildingExists) {
      addToCollisionTable(BuildingCollisions, getBuildingBox(i), i);
      buildingsAdded++;
    }
  }
  
  SPDLOG_INFO("Added {} buildings to collision table", buildingsAdded);
  
  // Rebuild lot collisions
  SPDLOG_INFO("Rebuilding lot collisions...");
  int lotsAdded = 0;
  for (int i = 1; i <= lots->size(); i++) {
    Lot* lot = getLot(i);
    if (lot->flags & _lotExists) {
      addToCollisionTable(LotCollisions, getLotBox(i), i);
      lotsAdded++;
    }
  }
  
  SPDLOG_INFO("Added {} lots to collision table", lotsAdded);
  SPDLOG_INFO("Collision table rebuild complete!");
}
