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

window.addEventListener("load", function() {
  fabriqueInterfaceGraphique(articles, tarifs);
  fabriqueCheckboxCategorie(articles);
  fabriqueCheckboxOrigine(tarifs);
});

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
      nouvelleCategorieElt.name = "cat_" + articles[i].catégorie;
      nouvelleCategorieElt.id = articles[i].catégorie;
      nouvelleCategorieElt.children[0].checked = false;
      nouvelleCategorieElt.children[1].textContent = articles[i].catégorie;
      categorieElt.appendChild(nouvelleCategorieElt);
    }
  }
}

function fabriqueCheckboxOrigine(tarifs) {
  for (i = 0; i < tarifs.length; i++) {
    let origineElt = document.getElementById('origines');
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
      nouvelleOrigineElt.name = "ori_" + tarifs[i].origine;
      nouvelleOrigineElt.id = tarifs[i].or
      nouvelleOrigineElt.children[0].checked = false;
      nouvelleOrigineElt.children[1].textContent = tarifs[i].origine;
      origineElt.appendChild(nouvelleOrigineElt);
    }
  }


}

function fabriqueInterfaceGraphique(articles, tarifs) {
  let dirImages = "./images/";

  for (i = 0; i < tarifs.length; i++) {
    let articleElt = document.getElementsByClassName('articles')[0];
    let nouvelArticleElt = articleElt.children[0].cloneNode();
    nouvelArticleElt.innerHTML = articleElt.children[0].innerHTML;
    let nouvelArticleImgStyle = nouvelArticleElt.getElementsByClassName('img')[0].style;
    let nouvelArticleName = nouvelArticleElt.getElementsByClassName('nom')[0];
    let nouvelArticleOrigin = nouvelArticleElt.getElementsByClassName('origine')[0];
    let nouvelArticlePrix = nouvelArticleElt.getElementsByClassName('prixUnitaire')[0];
    let nouvelArticleUnite1 = nouvelArticleElt.getElementsByClassName('unité')[0];
    let nouvelArticleUnite2 = nouvelArticleElt.getElementsByClassName('unité')[1];

    for (j = 0; j < articles.length; j++) {
      if (articles[j].ref == tarifs[i].ref) {
        let nouvelArticlePhoto = articles[j].photos[0];
        nouvelArticleImgStyle.backgroundImage = "url('" + dirImages + nouvelArticlePhoto.url + "')";
        nouvelArticleImgStyle.backgroundPositionX = -nouvelArticlePhoto.x + "px";
        nouvelArticleImgStyle.backgroundPositionY = -nouvelArticlePhoto.y + "px";
        nouvelArticleImgStyle.width = nouvelArticlePhoto.w + "px";
        nouvelArticleImgStyle.height = nouvelArticlePhoto.h + "px";
        nouvelArticleName.innerHTML = articles[j].nom;
      }
    }
    nouvelArticleOrigin.innerHTML = "Origine : " + tarifs[i].origine;
    nouvelArticlePrix.innerHTML = tarifs[i].prix;
    nouvelArticleUnite1.innerHTML = tarifs[i].unité;
    nouvelArticleUnite2.innerHTML = tarifs[i].unité;
    articleElt.appendChild(nouvelArticleElt);
  }
  let element = document.getElementsByClassName('articles')[0];
  let enfant = element.children[0];
  element.removeChild(enfant);
}

function decocher() {
  let origineElt = document.getElementById('origines');
  console.log(origineElt.children[1].children[1].checked);
}


function envoyerCommande() {
  let email = "destinataire@mail.com";
  let sujet = "commande de fruits et légumes";
  let corps = "\nCommande\n\nVoici un récapitulatif des articles commandés\npour un montant de 12.50 € :\n...\n..."
  email = encodeURIComponent(email);
  sujet = encodeURIComponent(sujet);
  corps = encodeURIComponent(corps);
  let uri = "mailto:" + email + "?subject=" + sujet + "&body=" + corps;
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


function filtrer(articles, tarifs) {
  let categories = document.getElementById('categories');
  let origines = document.getElementById('origines');
  tarifsBis = [];
  articlesBis = [];
  for (i = 2; i < categories.children.length; i++) {
    let categorie = categories.children[i];
    if (categorie.children[0].checked) {
      for (i = 0; j < tarifs.length; j++) {
        for (i = 0; j < articles.length; j++) {
          if (articles[j].origine == categorie[i].children[1].textContent) {
            articlesBis.push(articles[j]);
          }
        }
      }
    }
  }
  let article = document.getElementsByClassName("articles")[0]
  /*
  for (int i = 1; i < article.children.length; i++) {
    let enfant = article.children[i];
    article.removeChild(enfant);
  }
  */
  fabriqueInterfaceGraphique(articlesBis, tarifsBis);
}




function enleverArticle(tableau) {
  for (var i = tableau.rows.length; i-- > 0;) {
      var ligne = tableau.rows[i];
      var data = ligne.getElementsByTagName('input');
      for (var j = data.length; j-- > 0;) {
          var stockerData = data[j];

          if (stockerData.type ==='checkbox' && stockerData.checked) {
              ligne.parentNode.removeChild(ligne);
              break;
          }
      }
  }
  recalculerTotal();
}

function recalculerTotal() {
  var tableau = document.getElementById("tableID");
  var cellTotal = tableau.getElementsByClassName('totalPrixArticle')[0];
  var total = ' ';

  for (var i = 1; i < tableau.rows.length-1; i++) {
    var prices = tableau.rows[i].cells[3];

    if (prices != null)
     total += parseFloat(prices.innerHTML).toFixed(2);
}
   if (total > 0) {
    cellTotal.innerHTML = total;
  } else {
    cellTotal.innerHTML = "0.0";
  }
}

