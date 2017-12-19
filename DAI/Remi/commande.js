// console.log(JSON.stringify(articles));
// console.log(JSON.stringify(tarifs));

let panier = {
  total: 12.5,
  articles: [
    {
      article: 'Oranges',
      quantité: 3,
      prixUnitaire: 1.5,
      prix: 4.5
    }, {
      article: 'Fraises',
      quantité: 1,
      prixUnitaire: 8,
      prix: 8
    }
  ]
};

let tarifsBis = [];
let articlesBis = [];

window.addEventListener("load", function() {
  fabriqueInterfaceGraphique(articles, tarifs);
  fabriqueCheckboxCategorie(articles);
  fabriqueCheckboxOrigine(tarifs);
});

/* On ajout un eventListener onclick sur le document entier pour manipuler
   le site dunymiquement
*/
 document.body.addEventListener('click', function(e) {
    e = e || window.event;
    e = e.target || e.srcElement;

    switch (e.nodeName) {
      case 'CHECKBOX':
        if (e.id === 'origines')
          filtreOrigines(articles, tarifs, e.name);
        else if (e.className === 'modifier')
          modifierArticle();
        break;
      case 'BUTTON':
        // manipulation des boutons
        if (e.nodeName === 'BUTTON' && e.className !== 'enlever'
            && e.className !== 'envoyerCommande')
          ajouterPanier();
        else if (e.className === 'enlever')
          enleverTest(panier, tableID);
        else
          envoyerCommande(panier);
        break;
      case 'INPUT':
        // permet d'inserer que des chiffres dans les cases
        e.onfocus= e.select();
        e.onkeypress = function() {
          return event.charCode >= 48 && event.charCode <= 57;
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
  Cette fonction permet de fabriquer les checkboxes des categories
  @params: une variable articles qui corresond aux articles du site
  retourne: void
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
  Cette fonction permet de fabriquer les checkboxes des origines
  @params: une variable tarifs qui corresond aux tarifs du site
  retourne: void
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
  Cette fonction permet d'afficher toutes les articles du site
  @params: une variable articles qui corresond aux articles du site,
           une variable tarifs qui correspond aux tarifs du site
  retourne: void
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


// TODO: tester la fonction
window.onload=function()
{
    var p=document.getElementsByTagName('p');
    for(var i=0; i<p.length; i++)
    {
        p[i].id='x'+i; // An ID can't begin with a number, hence the "x".
        p[i].onclick=function()
        {
            alert(this.id.replace('x','')); // Remove "x" and [b]i[/b] remains.
        }
    }
}

// TODO: resoudre le probleme avec le click
/* function ajouterPanier(button) {
  var article = document.getElementsByClassName('articles')[0];
  var table = document.getElementById("tableID");
  var position = 0;

  var ligne = document.createElement('tr');
  var colArticle = document.createElement('td');
  var colQte = document.createElement('td');
  var textQte = document.createElement('input');
  textQte.type = "text";
  textQte.size = "1";
  var colPU= document.createElement('td');
  var colPrix = document.createElement('td');
  var colModifier = document.createElement('td')
  var checkModifier = document.createElement('input');
  checkModifier.type = "checkbox";

  //console.log(article.children[35].childNodes[3].children[4].nodeName);
  //console.log(button.nodeName);

  var a = article.children[35].childNodes[3].children[4];

  var len;
  var g = document.getElementsByTagName('button');
  for (var i = 0, len = article.children.length; i < len; i++)
  {
      (function(index){
          article.children[i].onclick = function(){
            if (article.children[i] === button) {
              console.log("text");
              var name = article.getElementsByClassName("nom")[index].innerHTML;
              var quantiteProduit = article.getElementsByClassName("quantiteProduit")[index].value;
              var puProduit =  article.getElementsByClassName("prixUnitaire")[index].textContent;
              var sommePrix = 0;

              sommePrix = quantiteProduit  * puProduit;

              colArticle.innerHTML = name;
              textQte.value = quantiteProduit;
              colPU.innerHTML = puProduit;
              colPrix.innerHTML = sommePrix.toFixed(2);
            } else {
              return;
            }
          }
      })(i);
  }
  ligne.appendChild(colArticle);
  colQte.appendChild(textQte);
  ligne.appendChild(colQte);
  ligne.appendChild(colPU);
  ligne.appendChild(colPrix);
  colModifier.appendChild(checkModifier);
  ligne.appendChild(colModifier);

  table.appendChild(ligne);

  recalculerTotal();
} */


/* function testPanier(button) {
  var nouvelleArticle = new Object();

  var article = document.getElementsByClassName('articles')[0];
  var table = document.getElementById("tableID");

  var ligne = document.createElement('tr');
  var colArticle = document.createElement('td');
  var colQte = document.createElement('td');
  var textQte = document.createElement('input');
  textQte.type = "text";
  textQte.size = "1";
  var colPU= document.createElement('td');
  var colPrix = document.createElement('td');
  var colModifier = document.createElement('td')
  var checkModifier = document.createElement('input');
  checkModifier.type = "checkbox";

  for (var i = 0; i < article.children.length; i++)
  {
      (function(index){
          article.children[i].childNodes[3].children[4].onclick = function(){
            var name = article.getElementsByClassName("nom")[index].innerHTML;
            var quantiteProduit = parseFloat(article.getElementsByClassName("quantiteProduit")[index].value);
            var puProduit = parseFloat(article.getElementsByClassName("prixUnitaire")[index].textContent);
            var sommePrix = parseFloat(sommePrix);

            sommePrix = quantiteProduit * puProduit;

            parseFloat(sommePrix.toFixed(2));

            // affectation des donnes aux variables d'objet nouvelleArticle
            nouvelleArticle.article = name;
            nouvelleArticle.quantité = quantiteProduit;
            nouvelleArticle.prixUnitaire = puProduit;
            nouvelleArticle.prix = sommePrix.toFixed(2);
          }
      })(i);
    }

  // NOTE: si je mets panier.articles.push(nouvelleArticle); dans la boucle
  // et colArticle.innerHTML = panier.articles.slice(-1)[0].article;
  // testCalculerTotal va marcher mais cela va buger pour l'ajout

  // insertion des nouvelles donnees dans la variable panier
  panier.articles.push(nouvelleArticle);

  // affectation des valeurs aux cases du tableau de panier
  colArticle.innerHTML = panier.articles.slice(-2)[0].article;
  textQte.value = panier.articles.slice(-2)[0].quantité;
  colPU.innerHTML = panier.articles.slice(-2)[0].prixUnitaire;
  colPrix.innerHTML = panier.articles.slice(-2)[0].prix;

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

  testCalculerTotal();

  console.log(panier.articles);
} */

function enleverTest(panier, tableau) {
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

  testCalculerTotal();
}


function testCalculerTotal() {
  var tableau = document.getElementById("tableID");
  var cellTotal = tableau.getElementsByClassName('totalPrixArticle')[0];
  var total = 0;
  var ligneCompteur = 0;

  for (var i = 1; i < tableau.rows.length-1; i++) {
    total += parseFloat(tableau.rows[i].cells[3].innerHTML);
    ligneCompteur++;
  }

  panier.total = total;

  if (total > 0) {
    cellTotal.innerHTML = total;
  } else {
    cellTotal.innerHTML = "0.0";
  }

  /* afficher label quand panier est vide est la supprimer apres */
  /* var ligne = document.createElement('tr');
  var panierVide = document.createElement('label');
  panierVide.type = 'label';

  console.log(panierVide.type);

  if (ligneCompteur === 0) {
    panierVide.innerHTML = "Votre panier est vide";

    ligne.appendChild(panierVide);
    tableau.appendChild(ligne);
  } else if (ligneCompteur > 0) {
    console.log(panierVide.type);
  } */
}

function envoyerCommande(panier) {
  let email = "destinataire@mail.com";
  let sujet = "LEGUFRUIT.fr : Confirmation de votre commande";
  let corps = "\nCommande\n ---------- \nVoici un récapitulatif des articles commandés\n pour un montant de €" + panier.total + " :\n\n";
  let recapitulatif = panier.articles + "\n";
  let footer = "\n\nNous vous remercions pour avoir choisi LEGUFRUIT.fr.\n";

  email = encodeURIComponent(email);
  sujet = encodeURIComponent(sujet);
  corps = encodeURIComponent(corps);
  recapitulatif = encodeURIComponent(recapitulatif);
  footer = encodeURIComponent(footer);
  let uri = "mailto:" + email + "?subject=" + sujet + "&body=" + corps + recapitulatif + footer;
  window.location.href = uri;
}

function categoriesCheck() {
  var categories = document.getElementById('categories');
  var toutes = document.getElementById('toutesCategories');
  var compteurCheckedBox = 0;

  compteurCheckedBox = calculerCategoriesCheckedBoxes();

  if (!categories.children[1].children[0].checked)
    categories.children[1].children[0].checked = true;

  toutes.addEventListener('click', decocherToutesCategories);

  if (compteurCheckedBox >= 1) {
    categories.children[1].children[0].checked = false;
  }
}

function decocherToutesCategories() {
  for (var i = 2; i < categories.children.length; i++) {
    categories.children[i].children[0].checked = false;
    categories.children[1].children[0].checked = true;
  }
}

function calculerCategoriesCheckedBoxes() {
  var categories = document.getElementById('categories');
  var compteur = 0;

  for (var i = 2; i < categories.children.length; i++) {
    if (categories.children[i].children[0].checked)
      compteur++;
  }
  return compteur;
}


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

function decocherToutesOrigines() {
  for (var i = 2; i < origines.children.length; i++) {
    origines.children[i].children[0].checked = false;
    origines.children[1].children[0].checked = true;
  }
}

function calculerOriginesCheckedBoxes() {
  var origines = document.getElementById('origines');
  var compteur = 0;

  for (var i = 2; i < origines.children.length; i++) {
    if (origines.children[i].children[0].checked)
      compteur++;
  }
  return compteur;
}

function ajouterPanier() {
  var nouvelleArticle = new Object();
  var articles = document.getElementsByClassName('articles')[0];
  var table = document.getElementById("tableID");

  var ligne = document.createElement('tr');
  var colArticle = document.createElement('td');
  var colQte = document.createElement('td');
  var textQte = document.createElement('input');
  textQte.type = "text";
  textQte.size = "1";
  colQte.className = "quantite";
  textQte.disabled = true;
  var colPU= document.createElement('td');
  var colPrix = document.createElement('td');
  var colModifier = document.createElement('td')
  var checkModifier = document.createElement('input');
  checkModifier.type = "checkbox";
  checkModifier.onclick = function() {
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

            parseFloat(sommePrix.toFixed(2));

            // affectation des donnes aux variables d'objet nouvelleArticle
            nouvelleArticle.article = name;
            nouvelleArticle.quantité = quantiteProduit;
            nouvelleArticle.prixUnitaire = puProduit;
            nouvelleArticle.prix = sommePrix.toFixed(2);

            // insertion des nouvelles donnees dans la variable panier
            panier.articles.push(nouvelleArticle);
        }
      })(i);
  }
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

    testCalculerTotal();
    console.log(panier.articles);
}

function getSelected(origines){
  var num = 0;
  var string = [];

  for (var i = 2; i < origines.children.length; i++) {
    if (origines.children[i].children[0].checked)
      string[i] = origines.children[2].children[1].innerHTML;
  }
  return string;
}

function supprimerArticles() {
  nbArticles = document.getElementsByClassName('article').length;
  i = 0;
  while (i<nbArticles-1) {
    let elt = document.getElementsByClassName('articles')[0];
    let prem = elt.children[0];
    elt.removeChild(prem);
    i++;
  }
}

// TODO: configurer ce filtre
function filtreCategories(articles, tarifs, choix) {
  let categories = document.getElementById('categories');
  let toutes = categories.children[1].children[0];

  if (toutes.checked) {
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


function filtreOrigines(articles, tarifs, choix) {
  let origines = document.getElementById('origines');
  let toutes = origines.children[1].children[0];

  if (toutes.checked) {
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

function modifierArticle() {
  var tableau = document.getElementById('tableID');

  parseFloat(tableau.rows[1].cells[3].innerHTML); // case prix
  parseFloat(tableau.rows[1].cells[1].children[0].value); // case quantité
  parseFloat(tableau.rows[1].cells[2].innerHTML); // case prix unitaire

  console.log(tableau.rows.length);

  for (var i = 1; i < tableau.rows.length-1; i++) {
    if (tableau.rows[i].cells[4].children[0].checked) {
      tableau.rows[i].cells[3].innerHTML = "";
      tableau.rows[i].cells[3].innerHTML += tableau.rows[i].cells[1].children[0].value * tableau.rows[i].cells[2].innerHTML;
      break;
    }
  }
  testCalculerTotal();
}

function ajouterElt() {
  var article = document.getElementsByClassName('article');
  let nouvelArticle = article.children[0].innerHTML;

  article.appendChild(nouvelArticle);
}
