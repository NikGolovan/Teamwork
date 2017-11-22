void menuGlobal(){
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║     GESTION GLOBALISEE DES SECOURS     ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Déclenchement d'une alerte        ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Nouvelle alerte                   ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Créer une unité                   ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Traitement des alertes            ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 5  ║ Gestion des unités disponibles    ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ Consultation des unités déployées ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -1 ║ Quitter                           ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuTraitementAlerte() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║        TRAITEMENT D'UNE ALERTE         ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Afficher une alerte               ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Modifier une alerte               ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Afficher toutes les alertes       ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Supprimer une alerte              ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuNiveauAlerte() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║                 NIVEAU                 ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ NOMINAL                           ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ URGENT                            ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ URGENCE ABSOLUE                   ║\n");
  printf("║    ║                                   ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuTypeAlerte() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║                  TYPE                  ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ INCENDIE                          ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ ACCIDENT DE LA ROUTE              ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ ACCIDENT EN MER                   ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ ACCIDENT EN MONTAGNE              ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 5  ║ MALAISE                           ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 6  ║ EXPLOSION                         ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 7  ║ ACCIDENT DE LA VIE                ║\n");
  printf("║    ║                                   ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}



void menuTraitementUnite() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║            GESTION DES UNITES          ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ Afficher une unité                ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ Afficher toutes les unités        ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ Modifier une unité                ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 4  ║ Supprimer une unité               ║\n");
  printf("║    ║                                   ║\n");
  printf("╠════╬═══════════════════════════════════╣\n");
  printf("║ -2 ║ Retourner                         ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuDeplacementUnite() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║          MOYEN DE DEPLACEMENT          ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ ROUTE                             ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ AIR                               ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ MER                               ║\n");
  printf("║    ║                                   ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuDisponibiliteUnite() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║         NIVEAU DE DISPONIBILITE        ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ ACTIVITE                          ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ EN REPOS                          ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ EN REAPROVISIONNEMENT             ║\n");
  printf("║    ║                                   ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}

void menuStatutUnite() {
  printf("╔════════════════════════════════════════╗\n");
  printf("║                                        ║\n");
  printf("║                 STATUT                 ║\n");
  printf("║                                        ║\n");
  printf("╠════╦═══════════════════════════════════╣\n");
  printf("║    ║                                   ║\n");
  printf("║ 1  ║ EN ALERTE                         ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 2  ║ EN ROUTE                          ║\n");
  printf("║    ║                                   ║\n");
  printf("║ 3  ║ SUR OPERATION                     ║\n");
  printf("║    ║                                   ║\n");
  printf("╚════╩═══════════════════════════════════╝\n");
}
