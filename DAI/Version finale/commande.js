// console.log(JSON.stringify(articles));
// console.log(JSON.stringify(tarifs));

/* le panier qui permet de stocker les articles */
let panier = {
  total: 0.0,
  articles: []
};

/* variables globales qui permettent de filtrer les articles */
let tarifsBis = [];
let articlesBis = [];

/* un even listener qui affiche les articles et les checkboxes quand la page est chargée */
window.addEventListener("load", function() {
  fabriqueInterfaceGraphique(articles, tarifs);
  fabriqueCheckboxCategorie(articles);
  fabriqueCheckboxOrigine(tarifs);
});

/*
 *
 *
 *
 */

/*
 * On ajout un eventListener onclick sur le document entier pour  pouvoir manipuler
 * le site dunymiquement
 */
 document.body.addEventListener('click', function(e) {
    e = e || window.event;
    e = e.target || e.srcElement;

    switch (e.nodeName) {
      case 'CHECKBOX':
        if (e.id === 'origines')
          filtOrigines(articles, tarifs, e.name);
        else if (e.className === 'modifier')
          modifierArticle();
        break;
      case 'BUTTON':
        // manipulation des boutons
        if (e.nodeName === 'BUTTON' && e.className !== 'enlever'
            && e.className !== 'envoyerCommande')
          ajouterPanier();
        else if (e.className === 'enlever')
          supprimerArticle(panier, tableID);
        else
          envoyerCommande(panier);
        break;
      case 'INPUT':
        // permet d'inserer que des chiffres dans les cases
        e.onfocus= e.select(e);
        e.onkeypress = function(event) {
        if (event.charCode > 31 && (event.charCode < 48 || event.charCode > 57)) {
            return false;
        }
        return true;
        }
        // met la case a 0 si elle vide et n'est plus sur focus
        e.onblur = function() {
          if (e.value === "")
            e.value = 0;
        }
      default:
        break;
    }
});

/*
 *  Cette fonction permet de fabriquer les checkboxes des categories
 *  @params: articles - variable globale
 *  return: void
 */
function fabriqueCheckboxCategorie(articles) {
  for (i = 0; i < articles.length; i++) {
    let categorieElt = document.getElementById('categories');
    categorieElt.children[1].children[0].checked = true;
    j = 2;
    deja = false;
    while (j < categorieElt.children.length && !deja) {
      if (articles[i].catégorie.localeCompare(categorieElt.children[j].children[1].innerHTML)===0) {
        deja = true;
      }
      j++;
    }
    if (!deja) {
      let nouvelleCategorieElt = categorieElt.children[1].cloneNode();
      nouvelleCategorieElt.innerHTML = categorieElt.children[1].innerHTML;
      nouvelleCategorieElt.children[0].name = articles[i].catégorie;
      nouvelleCategorieElt.children[0].id = articles[i].catégorie;
      nouvelleCategorieElt.children[0].checked = false;
      nouvelleCategorieElt.children[1].textContent = articles[i].catégorie;
      categorieElt.appendChild(nouvelleCategorieElt);
    }
  }
}

/*
 *  Cette fonction permet de fabriquer les checkboxes des origines
 *  @params: tarifs - variable globale
 *  return: void
 */
function fabriqueCheckboxOrigine(tarifs) {
  for (i = 0; i < tarifs.length; i++) {
    let origineElt = document.getElementById('origines');
    origineElt.children[1].children[0].checked = true;
    j = 2;
    deja = false;
    while (j < origineElt.children.length && !deja) {
      if (tarifs[i].origine.localeCompare(origineElt.children[j].children[1].innerHTML)===0) {
        deja = true;
      }
      j++;
    }
    if (!deja) {
      let nouvelleOrigineElt = origineElt.children[1].cloneNode();
      nouvelleOrigineElt.innerHTML = origineElt.children[1].innerHTML;
      nouvelleOrigineElt.children[0].name = tarifs[i].origine;
      nouvelleOrigineElt.children[0].id = tarifs[i].or
      nouvelleOrigineElt.children[0].checked = false;
      nouvelleOrigineElt.children[1].textContent = tarifs[i].origine;
      origineElt.appendChild(nouvelleOrigineElt);
    }
  }
}

/*
 *  Cette fonction permet de fabriquer et afficher toutes les articles
 *  @params: articles - variable globale, tarifs - variable globale
 *  return: void
 */
function fabriqueInterfaceGraphique(articles, tarifs) {
  let dirImages = "./images/";

  for (i = 0; i < tarifs.length; i++) {
    for (j = 0; j < articles.length; j++) {
      if (articles[j].ref == tarifs[i].ref) {
        let articleElt = document.getElementsByClassName('articles')[0];
        let nouvelArticleElt = articleElt.children[0].cloneNode();
        nouvelArticleElt.innerHTML = articleElt.children[0].innerHTML;
        let nouvelArticleImgStyle = nouvelArticleElt.getElementsByClassName('img')[0].style;
        let nouvelArticleName = nouvelArticleElt.getElementsByClassName('nom')[0];
        let nouvelArticleOrigin = nouvelArticleElt.getElementsByClassName('origine')[0];
        let nouvelArticlePrix = nouvelArticleElt.getElementsByClassName('prixUnitaire')[0];
        let nouvelArticleUnite1 = nouvelArticleElt.getElementsByClassName('unité')[0];
        let nouvelArticleUnite2 = nouvelArticleElt.getElementsByClassName('unité')[1];
        let nouvelArticlePhoto = articles[j].photos[0];
        nouvelArticleImgStyle.backgroundImage = "url('" + dirImages + nouvelArticlePhoto.url + "')";
        nouvelArticleImgStyle.backgroundPositionX = -nouvelArticlePhoto.x + "px";
        nouvelArticleImgStyle.backgroundPositionY = -nouvelArticlePhoto.y + "px";
        nouvelArticleImgStyle.width = nouvelArticlePhoto.w + "px";
        nouvelArticleImgStyle.height = nouvelArticlePhoto.h + "px";
        nouvelArticleName.innerHTML = articles[j].nom;
        nouvelArticleOrigin.innerHTML = "Origine : " + tarifs[i].origine;
        nouvelArticlePrix.innerHTML = tarifs[i].prix;
        nouvelArticleUnite1.innerHTML = tarifs[i].unité;
        nouvelArticleUnite2.innerHTML = tarifs[i].unité;
        articleElt.appendChild(nouvelArticleElt);
      }
    }
  }
  let element = document.getElementsByClassName('articles')[0];
  let enfant = element.children[0];
  element.removeChild(enfant);
}

window.onload=function()
{
    var test = document.getElementById('toutesCategories');

  /*  for(var i=0; i<p.length; i++)
    {
        p[i].id='x'+i; // An ID can't begin with a number, hence the "x".
        p[i].onclick=function()
        {
            alert(this.id.replace('x','')); // Remove "x" and [b]i[/b] remains.
        }
    } */
}

/*
 *  Cette fonction permet de supprimer une ou plusieurs articles du panier.
 *  La suppression s'effectue pas seulement du tableau HTML mais aussi du panier
 *  qui est une vatiable globale.
 *  @params: panier - variable globale du type tableau qui contient des objets
 *           tableau - variable passée en paramétre du tableay HTML
 *  return: void
 */
function supprimerArticle(panier, tableau) {
  var s = [];

  for (var i = tableau.rows.length; i-- > 0;) {
      var ligne = tableau.rows[i];
      var data = ligne.getElementsByTagName('input');
      for (var j = data.length; j-- > 0;) {
          var stockerData = data[j];

          if (stockerData.type ==='checkbox' && stockerData.checked) {
              s.push(ligne.children[0].innerHTML);
              ligne.parentNode.removeChild(ligne);
              break;
          }
      }
  }

  // TODO: il faut corriger cette boucle, elle supprime toujours
  // le premiere element
  for (var i = 0; i < panier.articles.length; i++) {
    if (panier.articles[i].article === s[i]);
          panier.articles.splice(i, 1);
}
  console.log(s);
  console.log(panier.articles);

  calculerTotal();
}

/*
 * La fonction permet de calculer le total du panier selon les articles ajoutées
 * ou bien supprimées.
 * @params: pas d'arguments
 * return: void
 */
function calculerTotal() {
  var tableau = document.getElementById("tableID");
  var cellTotal = tableau.getElementsByClassName('totalPrixArticle')[0];
  var total = 0;
  var ligneCompteur = 0;

  for (var i = 1; i < tableau.rows.length-1; i++) {
    total += parseFloat(tableau.rows[i].cells[3].innerHTML);
    ligneCompteur++;
  }

  panier.total = total.toFixed(2);

  if (total > 0) {
    cellTotal.innerHTML = total.toFixed(2);
  } else {
    cellTotal.innerHTML = "0.0";
  }

  /* afficher label quand panier est vide est la supprimer apres */
  var ligne = document.createElement('tr');
  var panierVide = document.createElement('label');
  panierVide.type = 'label';

  console.log(panierVide.type);

  if (ligneCompteur === 0) {
    panierVide.style.color = "blue";
    panierVide.innerHTML = "Votre panier est vide";

    ligne.appendChild(panierVide);
    tableau.appendChild(ligne);
  } else {
    console.log("ss");
    panierVide.style.display = "none";
  }
}

/*
 *  La fonction recupére les valeurs du panier (variable) et permet ensuite d'envoyer
 *  la récapitulatif à l'utilisateur par mail.
 *  @params: panier - variable globale du type tableau qui contient des objets
 *  return: void
 */
 function envoyerCommande(panier) {
   let email = "destinataire@mail.com";
   let sujet = "LEGUFRUIT.fr : Confirmation de votre commande";
   let total = panier.total;
   let corps = "\n\t\t\t\t\t\tCommande\n\t\t\t\t\t\t ------------- \nVoici un récapitulatif des articles commandées pour un montant de " + total + " euros :\n\n";
   let footer = "\n\nNous vous remercions pour avoir choisi LEGUFRUIT.fr\n\n";
   var recapitulatif = [];
   var data = [];

   for (var i = 0; i < panier.articles.length; i++) {
     recapitulatif[i] = "Article :  " + panier.articles[i].article + "  Quantité :  " + panier.articles[i].quantité
      + "  Prix Unitaire :  " + panier.articles[i].prixUnitaire + "  Prix :  " + panier.articles[i].prix + "\n";
   }

   console.log(recapitulatif);

   // permet de supprimmer le signe ','
   data.push(recapitulatif.join(""));

   console.log(data);

   email = encodeURIComponent(email);
   sujet = encodeURIComponent(sujet);
   corps = encodeURIComponent(corps);
   data = encodeURIComponent(data);
   footer = encodeURIComponent(footer);

   let uri = "mailto:" + email + "?subject=" + sujet + "&body=" + corps + "\n" + data + "\n\nTotal : " + total + "\n" + footer;
   window.location.href = uri;
 }

/* BLOCK CHECBKOXES */

/*
 *  La fonction permet de selectionner ou deselectionner automatiquement la case
 *  'Toutes' des categories.
 *  @params: pas d'arguments
 *  return: void
 */
function categoriesCheck() {
  var categories = document.getElementById('categories');
  var toutesCheck = document.getElementById('toutesCategories');
  var compteurCheckedBox = 0;

  compteurCheckedBox = calculerCategoriesCheckedBoxes();

  if (!categories.children[1].children[0].checked)
    categories.children[1].children[0].checked = true;

  toutesCheck.addEventListener('click', decocherToutesCategories);

  if (compteurCheckedBox >= 1) {
    categories.children[1].children[0].checked = false;
  }
}

/*
 *  Dès que toutes les cases sont deselectionnées, la case 'Toutes' est cochée automatiquement
 *  @params: pas d'arguments
 *  return: void
 */
function decocherToutesCategories() {
  for (var i = 2; i < categories.children.length; i++) {
    categories.children[i].children[0].checked = false;
    categories.children[1].children[0].checked = true;
  }
}

/*
 *  Fonction retourne le nombre des cases cochées
 *  @params: pas d'arguments
 *  return: compteur - variable de type entier
 */
function calculerCategoriesCheckedBoxes() {
  var categories = document.getElementById('categories');
  var compteur = 0;

  for (var i = 2; i < categories.children.length; i++) {
    if (categories.children[i].children[0].checked)
      compteur++;
  }
  return compteur;
}

/*
 *  La fonction permet de selectionner ou deselectionner automatiquement la case
 *  'Toutes' des origines.
 *  @params: pas d'arguments
 *  return: void
 */
function originesCheck() {
  var origines = document.getElementById('origines');
  var toutes = document.getElementById('toutesOrigines');
  var compteurCheckedBox = 0;

  compteurCheckedBox = calculerOriginesCheckedBoxes();

  if (!origines.children[1].children[0].checked)
    origines.children[1].children[0].checked = true;

  toutes.addEventListener('click', decocherToutesOrigines);

  if (compteurCheckedBox >= 1) {
    origines.children[1].children[0].checked = false;
  }
}

/*
 *  Dès que toutes les cases sont deselectionnées, la case 'Toutes' est cochée automatiquement
 *  @params: pas d'arguments
 *  return: void
 */
function decocherToutesOrigines() {
  for (var i = 2; i < origines.children.length; i++) {
    origines.children[i].children[0].checked = false;
    origines.children[1].children[0].checked = true;
  }
}

/*
 *  Fonction retourne le nombre des cases cochées
 *  @params: pas d'arguments
 *  return: compteur - variable de type entier
 */
function calculerOriginesCheckedBoxes() {
  var origines = document.getElementById('origines');
  var compteur = 0;

  for (var i = 2; i < origines.children.length; i++) {
    if (origines.children[i].children[0].checked)
      compteur++;
  }
  return compteur;
}
/* FIN DU BLOCK CHECBKOXES */

/*
 *  La fonction permet d'ajouter une article dans le tableau panier et aussi
 *  de la stocker dans une variable globale panier
 *  @params: pas d'arguments
 *  return: void
 */
function ajouterPanier() {
  var nouvelleArticle = new Object();
  var articles = document.getElementsByClassName('articles')[0];
  var table = document.getElementById("tableID");

  var ligne = document.createElement('tr');
  var colArticle = document.createElement('td');
  var colQte = document.createElement('td');
  colQte.className = "quantite";
  var textQte = document.createElement('input');
  textQte.type = "text";
  textQte.size = "1";
//  textQte.disabled = true;
  var colPU= document.createElement('td');
  var colPrix = document.createElement('td');
  var colModifier = document.createElement('td')
  var checkModifier = document.createElement('input');
  checkModifier.type = "checkbox";
  checkModifier.onchange = function(checkModifier) {
      modifierArticle();
}

  for (var i = 0; i < articles.children.length; i++)
  {
      (function(index){
          articles.children[index].childNodes[3].children[4].onclick = function(){
            var name = articles.getElementsByClassName("nom")[index].innerHTML;
            var quantiteProduit = parseFloat(articles.getElementsByClassName("quantiteProduit")[index].value);
            var puProduit = parseFloat(articles.getElementsByClassName("prixUnitaire")[index].textContent);
            var sommePrix = parseFloat(sommePrix);

            sommePrix = quantiteProduit * puProduit;

            sommePrix.toFixed(2);

            // affectation des donnes aux variables d'objet nouvelleArticle
            nouvelleArticle.article = name;
            nouvelleArticle.quantité = quantiteProduit;
            nouvelleArticle.prixUnitaire = puProduit;
            nouvelleArticle.prix = sommePrix.toFixed(2);

            // si la quantité == 0, on donc empêche l'ajout d'article
            if (quantiteProduit == 0) {
              alert("Veuillez presicer la quantité");
              return;
            }

            // insertion des nouvelles donnees dans la variable panier
            panier.articles.push(nouvelleArticle);
        }
      })(i);
  }
    if (panier.articles.length == 0) {
      return;
    } else {
      // affectation des valeurs aux cases du tableau de panier
      colArticle.innerHTML = panier.articles.slice(-1)[0].article;
      textQte.value = panier.articles.slice(-1)[0].quantité;
      colPU.innerHTML = panier.articles.slice(-1)[0].prixUnitaire;
      colPrix.innerHTML = panier.articles.slice(-1)[0].prix;

        // insertion des nouvelles lignes et contenant les donnees de panier
      ligne.appendChild(colArticle);
      colQte.appendChild(textQte);
      ligne.appendChild(colQte);
      ligne.appendChild(colPU);
      ligne.appendChild(colPrix);
      colModifier.appendChild(checkModifier);
      ligne.appendChild(colModifier);

      // apparation de la nouvelle ligne avec toutes les donnees
      table.appendChild(ligne);

      calculerTotal();
      console.log(panier.articles);
  }
}

/*
 *  Permet de supprimer toutes les articles de la page. Cela nous permet de mettre
 *  à jour les filtres.
 *  @params: pas d'arguments
 *  return: void
 */
function supprimerArticles() {
  var nombreArticles = document.getElementsByClassName('article').length;
  var i = 0;
  while (i < nombreArticles-1) {
    let element = document.getElementsByClassName('articles')[0];
    let premiere = element.children[0];
    element.removeChild(premiere);
    i++;
  }
}

/*
 *  La fonction affiche les articles selon la catégorie et le choix d'utilisateur
 *  @params: articles - variable globale, tarifs - variable globale, choix -
             variable contenant le .name de la case cliquée qui permet de filtrer
             les données selon le choix d'utilisateur.
 *  return: void
 */
function filtreCategories(articles, tarifs, choix) {
  let categories = document.getElementById('categories');
  let checkToutes = categories.children[1].children[0];

  if (checkToutes.checked) {
    articlesBis = [];
    supprimerArticles();
    fabriqueInterfaceGraphique(articles, tarifs);
  } else {
    if (choix.checked) {
      for (i = 0; i < articles.length; i++) {
        for (j = 0; j < tarifs.length; j++) {
          if (articles[i].ref == tarifs[j].ref) {
            if (articles[i].catégorie == choix.name) {
              articlesBis.push(articles[i]);
            }
          }
        }
      }
    } else {
      for (i = articlesBis.length - 1; i >= 0; i--) {
        if (articlesBis[i].catégorie == choix.name) {
          articlesBis.splice(i,1);
        }
      }
    }
    for (i = 0; i < articlesBis.length; i++) {
    }
    supprimerArticles();
    fabriqueInterfaceGraphique(articlesBis, tarifs);
  }
}

/*
 *  La fonction affiche les articles selon la origines et le choix d'utilisateur
 *  @params: articles - variable globale, tarifs - variable globale, choix -
             variable contenant le .name de la case cliquée qui permet de filtrer
             les données selon le choix d'utilisateur.
 *  return: void
 */
function filtreOrigines(articles, tarifs, choix) {
  let origines = document.getElementById('origines');
  let checkToutes = origines.children[1].children[0];

  if (checkToutes.checked) {
    tarifsBis = [];
    supprimerArticles();
    fabriqueInterfaceGraphique(articles, tarifs);
  } else {
    if (choix.checked) {
      for(i = 0; i < articles.length; i++) {
        for(j = 0; j < tarifs.length; j++) {
          if(articles[i].ref == tarifs[j].ref) {
            if(tarifs[j].origine == choix.name) {
              tarifsBis.push(tarifs[j]);
            }
          }
        }
      }
    } else {
      for (i = tarifsBis.length - 1; i >= 0; i--) {
        if (tarifsBis[i].origine == choix.name) {
          tarifsBis.splice(i,1);
        }
      }
    }
    supprimerArticles();
    fabriqueInterfaceGraphique(articles, tarifsBis);
  }
}

/*
 *  Permet de recalculer le total et le prix d'article selon les modifications
 *  d'utilisateur
 *  @params: pas d'arguments
 *  return: void
 */
function modifierArticle() {
  var tableau = document.getElementById('tableID');

  parseFloat(tableau.rows[1].cells[3].innerHTML).toFixed(2); // case prix
  parseFloat(tableau.rows[1].cells[1].children[0].value).toFixed(2); // case quantité
  parseFloat(tableau.rows[1].cells[2].innerHTML).toFixed(2); // case prix unitaire

  for (var i = 1; i < tableau.rows.length-1; i++) {
    if (tableau.rows[i].cells[4].children[0].checked) {
      //tableau.rows[i].cells[1].children[0].disabled = false;
      tableau.rows[i].cells[3].innerHTML = "";
      tableau.rows[i].cells[3].innerHTML = tableau.rows[i].cells[1].children[0].value * tableau.rows[i].cells[2].innerHTML;
      break;
    } else if (tableau.rows[i].cells[4].children[0].checked && !tableau.rows[i].cells[4].children[0].checked){
      tableau.rows[i].cells[3].innerHTML = "";
      tableau.rows[i].cells[3].innerHTML = tableau.rows[i].cells[1].children[0].value * tableau.rows[i].cells[2].innerHTML;
      break;
      //tableau.rows[i].cells[1].children[0].disabled = true;
    }
  }
  calculerTotal();
}

/*
 *  La fonction génère un nombre aléatoire pour le numèro de ticket client
 *  @params: pas d'arguments
 *  return: un entier
 */
function genererNumeroCommande() {
  return(Math.floor((Math.random() * 1000) + 1));
}

/*
 *  La fonction permet d'imprimer un ticket en format PDF
 *  @params:panier - variable globale
 *  return: void
 */
function printTicket(panier) {
  var pdf = new jsPDF('p', 'pt');
  var articles = [];
  var headerTicket = `Article             qtE          P.U.         Prix`;
  var nombreArticles = 0;

  var centrerTicket = (pdf.internal.pageSize.width / 2) - (pdf.getStringUnitWidth(headerTicket) * pdf.internal.getFontSize() / 2);

  for (var i = 0; i < panier.articles.length; i++) {
    articles[i] = panier.articles[i].article + "          " + panier.articles[i].quantité + "          " + panier.articles[i].prixUnitaire + "          " +  panier.articles[i].prix + "\n\n";
    nombreArticles++;
  }

  pdf.text(250, 30, `LEGUFRUIT.fr`);
  pdf.text(250, 80, `Le ticket client`);
  pdf.text(230, 120, `Ticket numero : ` + genererNumeroCommande());
  pdf.text(170, 150, `********************************************`);
  pdf.text(60, 175, `Vous avez commande ` + nombreArticles + ` articles pour la somme totale de ` + panier.total + ' euros');
  pdf.text(headerTicket, centrerTicket, 210);
  pdf.text(articles, centrerTicket, 240);

  pdf.save('ticket.pdf');
}
