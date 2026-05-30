# Changelog

## [1.2.0] — 2026-05-30

### Ajouts
- **Véhicule "Viper"** — nouveau véhicule avec ses modèles, textures, sous-catégorie "Droid" et aperçu
- **Casques P2 ARF Shiny et Trooper** — nouveaux équipements avec traductions dans le stringtable
- **Fonction `fnc_payAllPlayers`** — paie tous les joueurs connectés simultanément avec notification
- **Vérification du mot de passe** dans le dialogue de connexion avec chaînes de caractères associées
- **Nouvelles munitions et équipements médicaux** dans les chargements des classes DC15S et DC15A

### Modifications
- Durée d'initialisation du système de fortification portée à **10 000** ; suppression de certains objets de fortification
- Simplification de la vérification des données du joueur dans `fnc_loadPlayer`
- Gestion des erreurs et délais améliorée pour `fnc_extractPlayerData` et `fnc_loadPlayer`

### Suppressions
- **`autoPayment`** — fonction supprimée et tous les appels associés nettoyés (remplacée par `fnc_payAllPlayers`)

### Divers
- `.gitignore` mis à jour pour exclure les fichiers `.blend`

---

## [1.1.0] — 2026-05-22

### Ajouts
- Ajout d’une fonction serveur pour créer et attribuer automatiquement un module Zeus à un joueur.
- Ajout d’un système de vérification de version entre la mission et le serveur.
- Mise à jour du template de description de mission avec la version `pc_missions_version`.
- Ajustement du respawn dans les missions générées : délai réduit à 5 secondes et respawn activé au démarrage.
- Mise à jour des compositions de mission `Base` et `Venator`.

### Modifications
- Remplacement des anciennes jumelles clone par les nouvelles `ls_clone_electrobinocularsCommander`.
- Mise à jour de l’arsenal avec les nouvelles électro-jumelles, dont la variante de nuit.
- Amélioration du système d’auto-paiement avec un log serveur pour confirmer les paiements effectués.
- Refactor de plusieurs fichiers pour améliorer la lisibilité et la maintenance.

### Corrections
- Correction de la détection des traits ACE Medic et EOD.
- Correction des actions du terminal de traits pour afficher correctement les options selon l’état du joueur.
- Correction de la mise à jour des données joueur en base de données.
- Rechargement automatique des données joueur après sauvegarde pour garder les variables locales à jour.
- Correction des types SQL utilisés pour l’enregistrement des profils joueur.
