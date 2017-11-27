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

  let poivronPhoto = articles[15].photos[0];
  let poivronsElt = document.getElementsByClassName('article')[1];
  let poivronImgStyle = poivronsElt.getElementsByClassName('img')[0].style;
  poivronImgStyle.backgroundImage = "url('" + dirImages + poivronPhoto.url + "')";
  poivronImgStyle.backgroundPositionX = -poivronPhoto.x + "px";
  poivronImgStyle.backgroundPositionY = -poivronPhoto.y + "px";
  poivronImgStyle.width = poivronPhoto.w + "px";
  poivronImgStyle.height = poivronPhoto.h + "px";

  let fraisePhoto = articles[29].photos[0];
  let fraisesElt = document.getElementsByClassName('article')[2];
  let fraiseImgStyle = fraisesElt.getElementsByClassName('img')[0].style;
  fraiseImgStyle.backgroundImage = "url('" + dirImages + fraisePhoto.url + "')";
  fraiseImgStyle.backgroundPositionX = -fraisePhoto.x + "px";
  fraiseImgStyle.backgroundPositionY = -fraisePhoto.y + "px";
  fraiseImgStyle.width = fraisePhoto.w + "px";
  fraiseImgStyle.height = fraisePhoto.h + "px";
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
