#include "StdAfx.h"
#include "MyCoupon.h"


MyCoupon::MyCoupon( String^ lpNom, String^ lpCode, String^ lpMontant, String^ lpQuantite, String^ lpTag ) {

	this->m_nom = lpNom;
	this->m_code = lpCode;
	this->m_montantRaw = lpMontant;
	this->m_montant = lpMontant->Substring( 0, 1 ) + "," + lpMontant->Substring( 1, 2 );
	this->m_quantite = lpQuantite;
	this->m_tag = lpTag;
}

void MyCoupon::addToQuantite(const Int32 ajoute) {

	Int32 newQuantite = Int32::Parse( this->quantite ) + ajoute;
	this->m_quantite = newQuantite.ToString();
}
