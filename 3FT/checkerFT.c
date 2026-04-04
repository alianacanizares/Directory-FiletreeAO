/*--------------------------------------------------------------------*/
/* CheckerFT.c                                                        */
/* Author:                                                            */
/*--------------------------------------------------------------------*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "checkerFT.h"
#include "dynarray.h"
#include "path.h"



/* see CheckerFT.h for specification */
boolean CheckerFT_Node_isValid(Node_T oNNode) {
   Node_T oNParent;
   Path_T oPNPath;
   Path_T oPPPath;

   /* Sample check: a NULL pointer is not a valid node */
   if(oNNode == NULL) {
      fprintf(stderr, "A node is a NULL pointer\n");
      return FALSE;
   }

   /* Sample check: parent's path must be the longest possible
      proper prefix of the node's path */
   oNParent = Node_getParent(oNNode);
   if(oNParent != NULL) {
      oPNPath = Node_getPath(oNNode);
      oPPPath = Node_getPath(oNParent);

      if(Path_getSharedPrefixDepth(oPNPath, oPPPath) !=
         Path_getDepth(oPNPath) - 1) {
         fprintf(stderr, "P-C nodes don't have P-C paths: (%s) (%s)\n",
                 Path_getPathname(oPPPath), Path_getPathname(oPNPath));
         return FALSE;
      }
   }

   return TRUE;
}

/*
   Performs a pre-order traversal of the tree rooted at oNNode.
   Returns FALSE if a broken invariant is found and
   returns TRUE otherwise.

   During the travesal it counts the node that it is checking and
   adds it to nodeCount.

   You may want to change this function's return type or
   parameter list to facilitate constructing your checks.
   If you do, you should update this function comment.
*/
static boolean CheckerFT_treeCheck(Node_T oNNode, size_t *nodeCount) {
   size_t ulIndex;

   if(oNNode!= NULL) {
      (*nodeCount)++;

      /* Sample check on each node: node must be valid */
      /* If not, pass that failure back up immediately */
      if(!CheckerFT_Node_isValid(oNNode))
         return FALSE;

      /* Recur on every child of oNNode */
      for(ulIndex = 0; ulIndex < Node_getNumChildren(oNNode); ulIndex++)
      {
         Node_T oNChild = NULL;
         int iStatus = Node_getChild(oNNode, ulIndex, &oNChild);

         if(iStatus != SUCCESS) {
            fprintf(stderr, "getNumChildren claims more children than getChild returns\n");
            return FALSE;
         }

         /* Check if node already exists */
         if (ulIndex < (Node_getNumChildren(oNNode) - 1)) {
         
            Node_T nextChild = NULL;
            int jStatus = Node_getChild(oNNode, ulIndex + 1, &nextChild);
            assert(nextChild != NULL);

            Path_T currentPath = Node_getPath(oNChild);
            Path_T nextPath = Node_getPath(nextChild);
            assert(currentPath != NULL);
            assert(nextPath != NULL);


            if(Path_comparePath(currentPath, nextPath) == 0) {
               fprintf(stderr, "Multiple children have the same path\n");
               return FALSE;
            }

            if(Path_comparePath(currentPath, nextPath) > 0) {
               fprintf(stderr, "Not in lexigraphical order\n");
               return FALSE;
            }
         }

         /* if recurring down one subtree results in a failed check
            farther down, passes the failure back up immediately */
         if(!CheckerFT_treeCheck(oNChild, nodeCount))
            return FALSE;
      }
   }
   return TRUE;
}

/* see CheckerFT.h for specification */
boolean CheckerFT_isValid(boolean bIsInitialized, Node_T oNRoot,
                          size_t ulCount) {


   size_t nodeCount = 0;
   
   /* Sample check on a top-level data structure invariant:
      if the FT is not initialized, its count should be 0. */
   if(!bIsInitialized && ulCount != 0)
      if(ulCount != 0) {
         fprintf(stderr, "Not initialized, but count is not 0\n");
         return FALSE;
      }

   
   /* Now checks invariants recursively at each node from the root, and counts
   the actual amount of nodes in the tree */
   if(!CheckerFT_treeCheck(oNRoot, &nodeCount))
      return FALSE;

   /* Checks the actual number of nodes against the expected number and returns
      an error on mismatch. */
   if (nodeCount != ulCount) {
      fprintf(stderr, "Count Mismatch\n");
         return FALSE;
   }

   /* Returns true if all previous recursive checks passed*/
   return TRUE;
}

