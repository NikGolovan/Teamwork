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

/* document.body.addEventListener('click', function(e) {
    e = e || window.event;
    e = e.target || e.srcElement;
    if (e.nodeName === 'BUTTON')
      console.log(e);
}); */

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
      nouvelleCategorieElt.children[0].name = "cat_" + articles[i].catégorie;
      nouvelleCategorieElt.children[0].id = articles[i].catégorie;
      nouvelleCategorieElt.children[0].checked = false;
      nouvelleCategorieElt.children[1].textContent = articles[i].catégorie;
      categorieElt.appendChild(nouvelleCategorieElt);
    }
  }
}

function fabriqueCheckboxOrigine(tarifs) {
  let origineElt = document.getElementById('origines');
  // on coche la case 'toutes' à chaque mis à jour de page
  origineElt.children[1].children[0].checked = true;
  for (i = 0; i < tarifs.length; i++) {
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
      nouvelleOrigineElt.children[0].name = "ori_" + tarifs[i].origine;
      nouvelleOrigineElt.children[0].id = tarifs[i].origine;
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

function ajouterPanier() {
  var ligne = document.createElement('tr');
  var colArticle = document.createElement('td');
  var colQte = document.createElement('td');
  var colPU= document.createElement('td');
  var colPrix = document.createElement('td');
  var colModifier = document.createElement('td');
  var sommePrix = 0.0;

  var nomProduit = document.getElementById("nomProduit");
  var quantiteProduit = document.getElementById("quantiteProduit");
  var puProduit = document.getElementById("puProduit");
  var prixProduit = document.getElementsByClassName("price");

  ligne.appendChild(colArticle);
  ligne.appendChild(colQte);
  ligne.appendChild(colPU);
  ligne.appendChild(colPrix);
  ligne.appendChild(colModifier);

  sommePrix = parseFloat(quantiteProduit.value) * parseFloat(puProduit.textContent);

  console.log(quantiteProduit.value);

  colArticle.innerHTML = nomProduit.textContent;
  colQte.innerHTML = quantiteProduit.value;
  colPU.innerHTML = puProduit.textContent;
  colPrix.innerHTML = sommePrix.toFixed(2);
  colModifier.innerHTML = "test";

  var table = document.getElementById("tableID");
  table.appendChild(ligne);

  recalculerTotal();
}

function test(nom) {
  var articles = document.getElementsByClassName('articles')[0];
  var table = document.getElementById("tableID");

  var name = articles.getElementsByClassName("nom")[0].innerHTML;

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

  colArticle.innerHTML = name;

  ligne.appendChild(colArticle);
  colQte.appendChild(textQte);
  ligne.appendChild(colQte);
  ligne.appendChild(colPU);
  ligne.appendChild(colPrix);
  colModifier.appendChild(checkModifier);
  ligne.appendChild(colModifier);

  table.appendChild(ligne);

  //articles.addEventListener('click', decocherToutes);
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





function filtrCategories(articles, choix) {
  var article = document.getElementsByClassName('articles')[0];
  var articlesTab = [];

  if (choix.name == 'cat_Légumes') {
    for (var i = 0; i < articles.length; i++) {
      if (articles[i].catégorie == 'Légumes')
        articlesTab.push(articles[i]);
    }
  }
  console.log(JSON.stringify(articlesTab));
  fabriqueInterfaceGraphique(articlesTab, tarifs);
}




function filtOrigines(articles, tarifs, choix) {
  let taille = document.getElementById('origines').children.length;
  let origines = document.getElementById('origines');
  let origine = origines.children[2].children[1].innerHTML;
  let toutes = origines.children[1].children[0];
  console.log(toutes.checked);
  if(toutes.checked===true)
  {
    nbArticles = document.getElementsByClassName('article').length;
    i = 0;
    while(i<nbArticles-1)
    {
      let elt = document.getElementsByClassName('articles')[0];
      let prem = elt.children[0];
      elt.removeChild(prem);
      i++;
    }
    fabriqueInterfaceGraphique(articles, tarifs);
  }
  else
  {
    tarifsBis = [];
    for(i=0; i<articles.length; i++)
    {
      for(j=0; j<tarifs.length; j++)
      {
        if(articles[i].ref===tarifs[j].ref)
        {
          if(tarifs[j].origine===origine)
          {
            tarifsBis.push(tarifs[j]);
          }
        }
      }
    }
  nbArticles = document.getElementsByClassName('article').length;
  i = 0;
  while(i<nbArticles-1)
  {
    let elt = document.getElementsByClassName('articles')[0];
    let prem = elt.children[0];
    elt.removeChild(prem);
    i++;
  }
  fabriqueInterfaceGraphique(articles, tarifsBis);
}
}





function afficherLegumes() {
  let article = document.getElementsByClassName('articles')[0];
  let dirImages = "./images/";

  //while (article.firstChild) {
  //    article.removeChild(article.firstChild);
  //}

  for (var i = 0; i < articles.length; i++) {
    if (articles[i].catégorie === 'Légumes')
    for (i = 0; i < tarifs.length; i++) {
      let nouvelArticleElt = article.children[0].cloneNode();
      nouvelArticleElt.innerHTML = article.children[0].innerHTML;
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
      article.appendChild(nouvelArticleElt);
    }
  }
}






function ajouterElt() {
  var article = document.getElementsByClassName('article');
  let nouvelArticle = article.children[0].innerHTML;


  article.appendChild(nouvelArticle);
}
