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
});

function fabriqueInterfaceGraphique(articles, tarifs) {
  let dirImages = "./images/";

  for (i = 0; i < 31; i++) {
    let articleElt = document.getElementsByClassName('articles')[0];
    let nouvelArticleElt = articleElt.children[0].cloneNode();
    nouvelArticleElt.innerHTML = articleElt.children[0].innerHTML;
    let nouvelArticleImgStyle = nouvelArticleElt.getElementsByClassName('img')[0].style;
    let nouvelArticleName = nouvelArticleElt.getElementsByClassName('nom')[0];
    let nouvelArticleOrigin = nouvelArticleElt.getElementsByClassName('origine')[0];
//    let nouvelArticlePrix = nouvelArticleElt.getElementById('prixUnitaire')[0];
//    console.log(nouvelArticleElt.getElementById('prixUnitaire')[0]);
//    let nouvelArticleUnite = nouvelArticleElt.getElementById('Unite')[0];

    for (j = 0; j < 31; j++) {
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
    nouvelArticleOrigin.innerHTML = tarifs[i].origine;
//    nouvelArticlePrix.innerHTML = tarifs[i].prix;
//    nouvelArticleUnite.innerHTML = tarifs[i].unité;
    articleElt.appendChild(nouvelArticleElt);
  }
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

function ajouterElt() {
  var article = document.getElementsByClassName('article');
  let nouvelArticle = article.children[0].innerHTML;


  article.appendChild(nouvelArticle);
}
