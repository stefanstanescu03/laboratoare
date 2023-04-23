#include <stdio.h>
#include <stdlib.h>

#include "../Headers/bst.h"

#include <stdio.h>
/*

            mar
  abjura         morcov
      chinoroz         tectonic
                  psilofita
*/
int main() {

    Node* root = NULL;

    root = insert(root, "mar", "este un fruct");
    root = insert(root, "morcov", "este o leguma");
    root = insert(root, "tectonic", "Ramură a geologiei care studiază structura scoarței terestre");
    root = insert(root, "abjura", "A renega public o credință religioasă, o doctrină, o părere etc.");
    root = insert(root, "chinoroz", "Funingine foarte fină, folosită la fabricarea unor vopsele, a cernelii de tipar etc.");
    root = insert(root, "psilofita", "Plantă critpogamă cu tulpinile ramificate dihotomic, care se înmulțește prin spori.");

    searchPrefix(root, "psi");

    return 0;
}