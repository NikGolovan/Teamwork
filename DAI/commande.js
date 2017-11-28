// console.log(JSON.stringify(articles));
console.log(JSON.stringify(tarifs));

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
    let nouvelArticlePhoto = articles[i].photos[0];
    let nouvelArticleImgStyle = nouvelArticleElt.getElementsByClassName('img')[0].style;
    let nouvelArticleName = document.getElementsByClassName('nom')[0].style;
    nouvelArticleImgStyle.backgroundImage = "url('" + dirImages + nouvelArticlePhoto.url + "')";
    nouvelArticleImgStyle.backgroundPositionX = -nouvelArticlePhoto.x + "px";
    nouvelArticleImgStyle.backgroundPositionY = -nouvelArticlePhoto.y + "px";
    nouvelArticleImgStyle.width = nouvelArticlePhoto.w + "px";
    nouvelArticleImgStyle.height = nouvelArticlePhoto.h + "px";
    nouvelArticleName = articles[i].nom;
    articleElt.appendChild(nouvelArticleElt);
  }
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
