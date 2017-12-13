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
  fabriqueCheckboxOrigine(tarifs);
});


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
  var toutesSelected = document.getElementById('toutesSelected');
  var fruitsSelected = document.getElementById('fruitsSelected');
  var legumesSelected = document.getElementById('legumesSelected');

  if (fruitsSelected.checked) {
    toutesSelected.checked = false;
  } else if (legumesSelected.checked) {
    toutesSelected.checked = false;
  }

  if (!toutesSelected.checked && !fruitsSelected.checked
      && !legumesSelected.checked)
    toutesSelected.checked = true;
}
/*
La fonction qui vérifie si les checkboxs de fruits et légumes ont été cochés.
Si non, elle coche la case "Toutes".
@params: aucun paramètre
returne: void
*/
function categoriesCheckTout() {
  var toutesSelected = document.getElementById('toutesSelected');
  var fruitsSelected = document.getElementById('fruitsSelected');
  var legumesSelected = document.getElementById('legumesSelected');

  fruitsSelected.checked = false;
  legumesSelected.checked = false;

  if (!fruitsSelected.checked && !legumesSelected.checked)
    toutesSelected.checked = true;
}

/*
La fonction qui vérifie si les checkboxs Espagne, France ou Maroc ont été cochés.
Si oui, elle décoche la case "Toutes".
@params: aucun paramètre
returne: void
*/
function originesCheck() {
  var toutesSelectedOrigine = document.getElementById('toutesSelectedOrigine');
  var espagneSelected = document.getElementById('espagneSelected');
  var franceSelected = document.getElementById('franceSelected');
  var marocSelected = document.getElementById('marocSelected');

  if (espagneSelected.checked) {
    toutesSelectedOrigine.checked = false;
  } else if (franceSelected.checked) {
    toutesSelectedOrigine.checked = false;
  } else if (marocSelected.checked) {
    toutesSelectedOrigine.checked = false;
  }

  if (!toutesSelectedOrigine.checked && !espagneSelected.checked
      && !franceSelected.checked && !marocSelected.checked)
        toutesSelectedOrigine.checked = true;
}
/*
La fonction qui vérifie si les checkboxs de fruits et légumes ont été cochés.
Si non, elle coche la case "Toutes".
@params: aucun paramètre
returne: void
*/
function originesCheckTout() {
  var toutesSelectedOrigine = document.getElementById('toutesSelectedOrigine');
  var espagneSelected = document.getElementById('espagneSelected');
  var franceSelected = document.getElementById('franceSelected');
  var marocSelected = document.getElementById('marocSelected');

  espagneSelected.checked = false;
  franceSelected.checked = false;
  marocSelected.checked = false;

  if (!espagneSelected.checked && !franceSelected.checked && !marocSelected.checked)
    toutesSelectedOrigine.checked = true;
}

function test() {
  var origines = document.getElementById('origines');

  for (var i = 2; i < origines.children.length; i++) {
    if (origines.children[1].children[0].checked)
      origines.children[i].children[0].checked = false;
  }
}

function ajouterElt() {
  var article = document.getElementsByClassName('article');
  let nouvelArticle = article.children[0].innerHTML;


  article.appendChild(nouvelArticle);
}
