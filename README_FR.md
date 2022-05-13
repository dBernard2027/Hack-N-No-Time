# Hack’n No Time
## Présentation du projet:
Hack’n No Time est un prototype de Hack’n Slash solo réalisé dans le cadre d’un test sur
Unreal Engine. Il utilise en grande partie mes compétences sur Unreal Engine, mais
aussi des assets tirées du Marketplace Epic et de quixel. Par ailleurs, il existe deux versions
du projet, une légère disponible ici et une plus lourde disponible sous demande avec Level Design Complet.
## Fonctionnalités:
- Compétences Communes aux Entités: Toutes les entités possèdent la possibilité
d'utiliser des compétences, qu' elles soient joueurs ou non joueurs. À l’aide d’un
design pattern de commande, l’entité va demander l’utilisation d’une compétence en
fonction de son index. Une fois la requête effectuée, si les conditions sont réunis
(Assez de mana, Cooldown à 0), l’entité va lancer sa compétence qui peut être:
  - Au corps à corps: Comme c’est le cas actuellement lorsque le joueur presse
Clic Gauche ou alors lorsque l’ennemie est à côté du joueur et qu’il l’attaque.
  - À distance: Comme c’est le cas lorsque le joueur presse Clic Droit, un
projectile part en direction du curseur infligeant des dégâts aux entités qui
passent au travers du projectile.
  - En AOE: Comme c’est le cas lorsque le joueur appuie sur Espace, un VFX
apparaît alors infligeant des dégâts aux entités se trouvant autour du joueur.

- Système de Faction: Les entités possèdent une faction, cette fonctionnalité est
visible en jeux puisque les ennemies
en marbre vont s’attaquer mutuellement car appartenant à la catégorie agressive et
les ennemies en mousse n'attaquent personne car passifs.

- IA: Les Entités non joueurs possèdent toutes une IA, lorsque le joueur entre dans
leur champ de vision, les entités l’ayant repéré le chasse jusqu’à arriver à portée
d’attaque. Une fois arrivé, elle utilise leur compétence. Si le joueur disparaît du
champ de vision, elles se rendent au dernier point de vision avant de retourner à
leur point de départ pour retourner se balader sur la map à la recherche de
joueurs.

- Statistique: Les entités possèdent toutes une quantité de mana et de point de vie.
Lorsque ces statistiques descendent à 0, une conséquence apparait (mort de l’entité
pour les PV, et l’impossibilité de lancer certaines compétences pour le mana)
- Mort: Lorsqu’une entité meurt, elle devient un ragdoll et s'écroule au sol.
