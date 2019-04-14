#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Kudos for providing elven names:
 * http://www.candlekeep.com/library/articles/elven_names.htm
 */

static const char *male_names[] = {
	"Abadda", "Abarat", "Adamar", "Adorellan", "Adresin",
	"Aduce", "Aelrindel", "Aerendyl", "Aermhar", "Aesar",
	"Aeson", "Afamrail", "Agis", "Aglanthol", "Ainesilver",
	"Aithlin", "Ajaar", "Akhelbhen", "Akkar", "Alabyran",
	"Albondiel", "Alinar", "Allain", "Alok", "Alosrin",
	"Althidon", "Amrynn", "Anarallath", "Andaerean", "Andrathath",
	"Anfalen", "Anlyth", "Aolis", "Aquilan", "Araevin",
	"Arandron", "Aravilar", "Arbane", "Ardreth", "Ardryll",
	"Argus", "Arkhun", "Arkiem", "Arl", "Arlen",
	"Arun", "Ascal", "Athtar", "Aubric", "Aubron",
	"Aulathar", "Aulauthar", "Aumanas", "Aumrauth", "Avourel",
	"Baerdelcoam", "Baerithryn", "Belanor", "Beldroth", "Bellas",
	"Belstram", "Beluar", "Bhyrindaar", "Biafyndar", "Bialaer",
	"Braern", "Brindarry", "Buttorwyr", "Cameron", "Chaalmyth",
	"Chathanglas", "Cheyrth", "Chozzaster", "Chylnoth", "Cluhurach",
	"Cluym", "Cohnal", "Conall", "Connak", "Cornaith",
	"Corym", "Cymbiir", "Cystenn", "Dalyor", "Dakath",
	"Dannyd", "Daratrine", "Darcassan", "Darfin", "Darthoridan",
	"Deldrach", "Delmuth", "Delsaran", "Dhoelath", "Divisav",
	"Drannor", "Droth", "Druindar", "Durlan", "Durothil",
	"Dyffros", "Earynspieir", "Edansyr", "Edicuve", "Edwyrd",
	"Edyrm", "Ehlark", "Ehrendil", "Eilauver", "Elaethan",
	"Elaith", "Elandorr", "Elanjar", "Elashor", "Elbauthin",
	"Elbereth", "Eldaernth", "Eldar", "Eldrin", "Elenaril",
	"Elenshaer", "Elephon", "Elhieardacil", "Elidyr", "Elion",
	"Elkhazel", "Ellisar", "Elorfindar", "Elorshin", "Elpaerae",
	"Eltaor", "Eltargrim", "Emmyth", "Entrydal", "Erendriel",
	"Erglareo", "Eriladar", "Erlan", "Erlathan", "Eroan",
	"Erolith", "Eschallus", "Estelar", "Ethlando", "Ettrian",
	"Euchoe", "Evindal", "Eyrynnhv", "Faahresc", "Faelar",
	"Faelyn", "Faeranduil", "Falael", "Faoraar", "Felaern",
	"Fenian", "Fflar", "Fhaornik", "Fhociin", "Filarion",
	"Filvendor", "Filverel", "Finufaranell", "Flardryn", "Flinar",
	"Foxfire", "Fylson", "Gaeleath", "Gaelin", "Galaeron",
	"Galan", "Galather", "Ganamede", "Gantar", "Garrik",
	"Garynnon", "Giilvas", "Giullio", "Glarald", "Glorandal",
	"Goronyyv", "Grathgor", "Haalaari", "Hachaam", "Haemir",
	"Haladavar", "Halafarin", "Halamar", "Haldreithen", "Halflar",
	"Halgondas", "Halpaeril", "Halueth", "Halueve", "Haryk",
	"Hastos", "Hatharal", "Hiflanyl", "Hoccar", "Horith",
	"Hubyr", "Iefyr", "Ievos", "Ihimbraskar", "Ilbryn",
	"Illianaro", "Ilimitar", "Iliphar", "Ilitharath", "Illithor",
	"Illitran", "Ilphas", "Ilrune", "Ilthuryn", "Ilyndrathyl",
	"Inchel", "Inialos", "Injros", "Intevar", "Iolas",
	"Iolrath", "Itham", "Ithraides", "Ivlisar", "Ivósaar",
	"Ivran", "Iymbryl", "Iyrandrar", "Iyriklaunavan", "Jandar",
	"Jannalor", "Jaonos", "Jassin", "Jhaan", "Jhaartael",
	"Jhaeros", "Jharak", "Jharym", "Jhuvik", "Jonas",
	"Jonik", "Jorildyn", "Josidiah", "Juppar", "Kahvoerm",
	"Kalaerede", "Katar", "Katyr", "Keletheryl", "Kelvhan",
	"Kendel", "Kerym", "Keryth", "Kesefehon", "Khaalindaan",
	"Kharis", "Khatar", "Khidell", "Khiiral", "Khilseith",
	"Khuumal", "Khyrmn", "Khyssoun", "Kindroth", "Kivessin",
	"Kiyuigh", "Klaern", "Kolvar", "Korrigash", "Kroloth",
	"Kuornos", "Kuskyn", "Kuskyn", "Kymil", "Kyrtaar",
	"Laeroth", "Lafarallin", "Lamruil", "Laosx", "Larongar",
	"Larrel", "Lashul", "Lathai", "Lathlaeril", "Leayonadas",
	"Leojym", "Lhombaerth", "Lhoris", "Lianthorn", "Llarm",
	"Llewellenar", "Llombaerth", "Lorsan", "Luirlan", "Luthais",
	"Luvon", "Lyari", "Lyklor", "Lysanthir", "Maasli",
	"Maendellyn", "Maeraddyth", "Maeral", "Maiele", "Malgath",
	"Mardeiym", "Marikoth", "Marlevaur", "Melandrach", "Melisander",
	"Merellien", "Merith", "Methild", "Mhaenal", "Mi'tilarro",
	"Mihangyl", "Miilaethorn", "Miirphys", "Mirthal", "Mirthal",
	"Mlartlar", "Mlossae", "Molonym", "Molostroi", "Montagor",
	"Morgan", "Morthil", "Mothrys", "Mourn", "Myrddin",
	"Myriil", "Myrin", "Myronthilar", "Mythanthar", "Naertho",
	"Naeryndam", "Naeryndam", "Napraeleon", "Narbeth", "Nardual",
	"Nelaeryn", "Nelaeryn", "Neldor", "Neldor", "Nesterin",
	"Nevarth", "Nhamashal", "Nieven", "Nindrol", "Ninthalor",
	"Nlossae", "Nopos", "Norlorn", "Nremyn", "Nuvian",
	"Nyaalsir", "Nylian", "Nym", "Nyvorlas", "Oacenth",
	"Oenel", "Ohmbryn", "Olaurae", "Olinsivver", "Olithir",
	"Onas", "Oncith", "Ondabrar", "Ondroth", "Onvyr",
	"Orist", "Orlpar", "Orndacil", "Ornthalas", "Ornthalas",
	"Ortaure", "Orym", "Oslarelar", "Otaehryn", "Otaerhyn",
	"Othorion", "Paeral", "Paeris", "Passilorris", "Paulorin",
	"Phaendar", "Pharom", "Phraan", "Pirphal", "Pleufan",
	"Purtham", "Pyrder", "Pyrravym", "Pywaln", "Pyxaanthal",
	"Qildor", "Quastarte", "Quynn", "Raeranthur",
	"Raibyr", "Ralikanthae", "Ralnor", "Rathal", "Raunaeril",
	"Rauthomyr", "Rauvelore", "Reluraun", "Reluvethel", "Rennyn",
	"Reptar", "Respen", "Rhaac'var", "Rhalyf", "Rhangyl",
	"Rhenalyrr", "Rhespen", "Rhistel", "Rhothomir", "Rhys",
	"Rilitar", "Riluaneth", "Rolim", "Rotheloe", "Rothilion",
	"Ruardh", "Ruehar", "Ruith", "Rumathil", "Ruvaen",
	"Ruven", "Ruvyn", "Rychell", "Ryfon", "Ryul",
	"Ryvvik,", "Sadalymn", "Saevel", "Sakrattars",
	"Samblar", "Sandevv", "Seanchai", "Seith", "Selanlar",
	"Selgauth", "Shael", "Shammath", "Sharian", "Sharlario",
	"Shaundyl", "Shevarash", "Shonassir", "Shyrrik", "Siirist",
	"Silvyr", "Simimar", "Sinaht", "Skalanis", "Sontar",
	"Srindin", "Strohm", "Sudryl", "Sundamar", "Sylvar",
	"Symkalr", "Sythaeryn", "Taanyth", "Taegen", "Taeglyn",
	"Taeral", "Taerntym", "Taleisin", "Tammson", "Tamnaeuth",
	"Tamsin", "Tanithil", "Tannivh", "Tannyll", "Tanseril",
	"Tanyl", "Taranath", "Tarathiel", "Taredd", "Tarosspur",
	"Tarron", "Tasar", "Tassarion", "Tathaln", "Tehlmar",
	"Teirist", "Tenyajn", "Tethir", "Thalanil", "Thallan",
	"Thatoryl", "Thiilthan", "Thurdan", "Thurruvyn", "Tiarshus",
	"Tlannatar", "Tolthe", "Tordynnar", "Toross", "Traeliorn",
	"Travaran", "Triandal", "Triktappic", "Tsaer", "Tsiilmas",
	"Tyvollus", "Saelethil", "Saevel", "Sakrattars", "Seiveril",
	"Sharian", "Skalanis", "Sinaht", "Sudryl", "Sythaeryn",
	"Taenaran", "Tannivh", "Tamnaeuth", "Tanyl", "Tarathiel",
	"T'karon", "Tolthe", "Traeliorn", "Ualair", "Uevareth",
	"Uldreiyn", "Uldreiyn", "Urddusk", "Usunaar", "Uthorim",
	"Vaalyun", "Vaeril", "Valmaxian", "Vander", "Vartan",
	"Velethuil", "Venali", "Vesperr", "Vesryn", "Vesstan",
	"Vhoadan", "Vhoori", "Vhoorhin", "Volodar", "Voron",
	"Waernas", "Wistari", "Wylchyr", "Wylym", "Wyn",
	"Wyndelleu", "Wyqhael", "Wyrran", "Xalph", "Xanotter",
	"Xhalh", "Xhalth", "Xharlion", "Yalathanil", "Yeschant",
	"Yhendorn", "Ylyndar", "Ynloeth", "Zabbas", "Zaltarish",
	"Zandro", "Zaor", "Zaos", "Zelphar", "Zhoron", "Zulae"
};

static const char *female_names[] = {
	"Aelieyeeva", "Aelrue", "Aelynthi", "Aerilaya", "Ahrendaaria",
	"Ahrendue", "Ahskahala", "Ajhalanda", "Alaglossa", "Alais",
	"Alauthshaee", "Alavara", "Alea", "Alerathla", "Allannia",
	"Allisa", "Alloralla", "Allynna", "Almithara", "Aloevan",
	"Alvaerele", "Aluendalee", "Alyndra", "Amara", "Amaranthae",
	"Amkissra", "Amlaruil", "Amnestria", "Amra", "Anaharae",
	"Anarzee", "Aneirin", "Anhaern", "Anyllan", "Ara",
	"Araushnee", "Aravae", "Arcaena", "Arielimnda", "Arlayna",
	"Arnarra", "Artin", "Ashemmi", "Aubaudameira", "Auluua",
	"Aurae", "Ava", "Axilya", "Ayaeqlarune", "Azariah",
	"Bhuraelea", "Blythswana", "Bonnalurie", "Braerindra", "Caerthynna",
	"Calarel", "Cauladra", "Chaenath", "Chalsarda", "Chandrelle",
	"Chasianna", "Chichlandra", "Chin'nesstre", "Chomylla", "Cilivren",
	"Ciyradyl", "Claire", "Csharynn", "Daenalaia", "Daratrine",
	"Darshee", "Dasyra", "Dathlue", "Dathlue", "Dathlue",
	"Delimbiyra", "Delshandra", "Deularla", "Duilya", "Eallyrl",
	"Ecaeris", "Edraele", "Elanalue", "Elanil", "Elasha",
	"Eldratha", "Elenaril", "Eletha", "Ellarian", "Ellifain",
	"Eloen", "Elora", "Elvandaruil", "Embrae", "Emvorele",
	"Enajharas", "Eshenesra", "Essaerae", "Esta", "Ester",
	"Esyae", "Faranni", "Faunalyn", "Fhaertala", "Fieryat",
	"Filaurel", "Filauria", "Fildaerae", "Fox-at-Twilight", "Francessca",
	"Gaelira", "Gaerradh", "Gaylia", "Gemstarzah", "Ghilanna",
	"Glynnii", "Gweyr", "Gwynnestri", "Gylledha", "Haalija",
	"Hacathra", "Halaema", "Halama", "Halaema", "Halanaestra",
	"Hamalitia", "Haramara", "Helartha", "Hhora", "Holone",
	"Huquethae", "Hycis", "Iahalae", "Ialantha", "Ikeshia",
	"Ildilyntra", "Ilmadia", "Ilyrana", "Ilythyrra", "Imdalace",
	"Imizael", "Immianthe", "Imra", "Imramarthree", "Imryll",
	"Innovindil", "Ioelena", "Irhaal", "Isciira", "Ithrythra",
	"Itiireae", "Itylra", "Jastra", "Jeardra", "Jhaer",
	"Jhalass", "Jhanandra", "Jhaumrithe", "Jhiilsraa", "Ilsevel",
	"Ilyrana", "Immianthe", "Isilfarrel", "Kavrala", "Kaylessa",
	"Keerla", "Keishara", "Kethryllia", "Keya", "Khiipaera",
	"Kileontheal", "Kythaela", "Laamtora", "Laerdya", "Laerune",
	"Laurlaethee", "Lazziar", "Leilatha", "Liluth", "Llamryl",
	"Lorelei", "Lydi'aleera", "Lyraesel", "Maaleshiira", "Maelyrra",
	"Maeralya", "Maith", "Makaela", "Malruthiia", "Mariona",
	"Marissa", "Martainn", "Meira", "Melarue", "Merethyl",
	"Merialeth", "Meriel", "Merlara", "Mistale", "Mladris",
	"Mnuvae", "Morgwais", "Moryggan", "Muerlara", "Mylaela",
	"Mylaerla", "Myriani", "Naevys", "Nakiasha", "Nambra",
	"Namyriitha", "Nanalethalee", "Nanthee", "Nanthleene", "Naumys",
	"Nlaea", "Nuala", "Nueleth", "Nuovis", "Nushala",
	"Nylaathria", "Ochyllyss", "Oluevaera", "Phaerl", "Phantyni",
	"Phelorna", "Phuingara", "Phyrra", "Pollae", "Puorlaas",
	"Qemba", "Quamara", "Raejiisa", "Raerauntha", "Rathiain",
	"Renestrae", "Roanmara", "Ruavia", "Rubrae", "Ryllae",
	"Saelihn", "Saelihn", "Saida", "Sakaala", "Sariandi",
	"Sarya", "Schimae", "Seirye", "Seldanna", "Selussa",
	"Seonais", "Shael", "Shadowmoon", "Shalana", "Shalantha",
	"Shalendra", "Shalheira", "Shandalar", "Shanyrria", "Sharaera",
	"Sheedra", "Sheera", "Shialaevar", "Shi'larra", "Shialaevar",
	"Shoulree", "Shyael", "Shyael", "Shyllisyrr", "Sinnafain",
	"Soliania", "Soora", "Sorsasta", "Susklahava", "Sylmae",
	"Symrustar", "Syndra", "Synnorha", "Syrune", "Syviis",
	"Taenya", "Takari", "Talaedra", "Talanashta", "Talila",
	"Talindra", "Tamara", "Tarasynora", "Teharissa", "Teryani",
	"Thalaera", "Thalanil", "Thaola", "Thasitalia", "Throleatha",
	"Tiatha", "Tira'allara", "Tiriara", "Tisharu", "Tsarra",
	"Tyllaetha,", "Ulelesse", "Unae", "Urmicca",
	"Uschymna", "Vaervenshalice", "Valindra", "Vashti", "Velaethaunyl",
	"Velatha", "Veluthil", "Verrona", "Vestele", "Viansola",
	"Winterflower", "Xiiltharra", "Yaereene", "Yalanilue", "Yathlanae",
	"Yeshelne", "Yghiilra", "Ygrainne", "Ynshael", "Yrlissa",
	"Yrneha", "Yrthraethra", "Ysmyrlda", "Ytharra", "Yulmanda",
	"Z'Beryl", "Zhuirentel", "Zoastria"
};

static const char *surnames[] = {
	"Aelasar", "Aelorothi", "Aendryr", "Aerasume", "Aeravansel",
	"Agayous", "Agrivar", "Ahmaquissar", "Alaenree", "Alantar",
	"Alavara", "Alastrarra", "Alenuath", "Alerothi", "Alluth",
	"Aloevan", "Aluianti", "Aluviirsaan", "Amalith", "Amarallis",
	"Amaratharr", "Amarthen", "Ammath", "Amrallatha", "Anuaer",
	"Argentaamn", "Arren", "Ash", "Ashgrove", "Audark",
	"Auglamyr", "Auglathla", "Aunglor", "Autumnfire", "Bellas",
	"Berethryl", "Berilan", "Bharaclaiev", "Bhephel", "Blackhelm",
	"Braegen", "Briarbosk", "Brightcloak", "Brightsong", "Brightwing",
	"Caersaelk", "Calaudra", "Calauth", "Camusiil", "Cathdeiryn",
	"Ceretlan", "Chaadren", "Chamaranthe", "Clatharla", "Cormyth",
	"Coudoarluth", "Craulnober", "Crystalembers", "Dahast", "Dawnhorn",
	"Dhorinshyl", "Dlardrageth", "Doedance", "Donnathlascen", "Dracoseir",
	"Dree", "Duirsar", "Durothil", "Duskmere", "Duthjuth",
	"Ealoeth", "Echorn", "Elaeyadar", "Elassidil", "Elian",
	"Ellarian", "Elond", "Eluarshee", "Ereuvyn", "Erkowe",
	"Erladden", "Eroth", "Erlshade", "Estelda", "Evanara",
	"Eveningfall", "Everlove", "Evioro", "Eyriendor", "Faerondaerl",
	"Faerondarl", "Falanae", "Felinaun", "Fellmirr", "Fenmarel",
	"Fflannidan", "Floshin", "Fynnasla", "Gildenguard", "Goadulphyn",
	"Goldenleaf", "Gourael", "Greencloak", "Gwaelon", "Haell",
	"Haerlgent", "Haladar", "Hawksong", "Haevaul", "Halavanthlarr",
	"Hlarr", "Hyshaanth", "Iazymnal", "Ibryiil", "Ilbaereth",
	"Ilbenalu", "Ildacer", "Ildroun", "Iliathor", "Iliathor",
	"Iliathorr", "Ilnatar", "Immeril", "Ipyllasc", "Irian",
	"Irithyl", "Irithyl", "Ithruen", "Iydril", "Jaglene",
	"Kadelaryn", "Kelerandri", "Kelpor'ral", "Keove", "Kevanarial",
	"Korianthil", "Kraok", "Laelithar", "Laralytha", "Larenthanil",
	"Larethian", "Laughingwater", "Leafbower", "Leafsigil", "Le'Quella",
	"Lharithlyn", "Lhoril", "Llundlar", "Loceath", "Lightshiver",
	"Maendellyn", "Maerdrym", "Melruth", "Meirityn", "M'Haaren",
	"Miritar", "Mistrivvin", "Mistwinter", "Mithalvarin", "Moonbow",
	"Moondown", "Moonflower", "Moonglade", "Moonglamaer", "Moonsnow",
	"Moonweather", "Morningdove", "Mornmist", "Mrhulaedir", "Nacnar",
	"Naelgrath", "Narlbeth", "Narlbeth", "Neirdre", "Nelnueve",
	"Never", "Nhachashaal", "Nhaeslal", "Nharimlur", "Nightstar",
	"Nightwing", "Nihmedu", "Ni'Tessine", "Nierde", "Nightmeadow",
	"Nimesin", "Nlossae", "Nlossae", "Nolbrae", "Nyamtharsar",
	"Nyntynel", "Oakstaff", "Oakwood", "Olortynnal", "Olyrnn",
	"Omberdawn", "Ongluth", "Orama", "Orbryn", "Orbryn",
	"Ortaure", "Oumryn", "Phenthae", "Pholont", "Presrae",
	"Q'Naepp,", "Rachiilstar", "Raedrimn", "Raryndur",
	"Reithel", "Revven", "Rhaevaern", "Rhothomir", "Rhuidhen",
	"Rhyllgallohyr", "Rivleam", "Rivvikyn", "Runemaster", "Sarsantyr",
	"Selakiir", "Selmer", "Selorn", "Shadowmantle", "Shadowwater",
	"Shaeremae", "Shaethe", "Shalandalan", "Sharrith", "Shaurlanglar",
	"Shraiee", "Shyr", "Sicafei", "Siltral", "Silverbow",
	"Silverhand", "Silveroak", "Silverspear", "Sinaran", "Slenderbow",
	"Spellstalker", "Soryn", "Srinshee", "Starnar", "Starbrow",
	"Starglance", "Starglow", "Starym", "Stillhawk", "Stilmyst",
	"Straeth", "Strongbow", "Suldusk", "Sultaasar", "Summerstars",
	"Sunweaver", "Swordstar", "Symbaern", "Talandren", "Talesspur",
	"Tamlyranth", "Tanagathor", "Tarnruth", "Tarsap", "Tarsis",
	"Tassarion", "Taurntyrith", "Tellynnan", "Teshurr", "Thea",
	"Tlanbourn", "Tohrthaal", "Toralynnsyr", "Tornglara", "Tornglara",
	"Torthtan", "Toryvhallen", "Trueshot", "Tsornyl", "Tyrneladhelu",
	"Uirthur", "Ulondarr", "Ulongyr", "Vandiir", "Veverell",
	"Vispasial", "Vyshaan", "Waelvor", "Whitethistle", "Windstar",
	"Windwalker", "Xantrani", "Yeschant", "Yhendorn", "Yraueme",
	"Yridnae", "Yundraer"
};

#define MAX_MIXEDNAME_LEN		32U

static void mix_names(const char *first_name, const char *last_name,
		char *mix_name, size_t len)
{
	size_t i;
	char mixer[256];
	unsigned int new_value;

	strcpy(mixer, first_name);
	strcat(mixer, last_name);

	memset(mix_name, 0, len);
	for (i = 0; i < (strlen(first_name) + strlen(last_name)) % 256; i++) {
		new_value = mix_name[i % MAX_MIXEDNAME_LEN];
		new_value += mixer[i];
		mix_name[i % MAX_MIXEDNAME_LEN] = new_value % 26 + 97;
	}
}

static const char *get_first_name(const char *mix_name, size_t len,
		unsigned char type)
{
	size_t i;
	size_t sum;
	const char **names;
	size_t names_len;

	sum = 0;
	for (i = 0; i < len; i += 2)
		sum += (unsigned int) mix_name[i] * 3 + 7;

	if (type == 1) {
		names = male_names;
		names_len = sizeof(male_names) / sizeof(male_names[0]);
	}
	else {
		names = female_names;
		names_len = sizeof(female_names) / sizeof(female_names[0]);
	}

	return names[sum % names_len];
}

static const char *get_surname(const char *mix_name, size_t len,
		unsigned char type)
{
	size_t i;
	size_t sum;
	size_t names_len;

	sum = 0;
	for (i = 1; i < len; i += 2)
		sum += (unsigned int) mix_name[i] * 3 + 11;

	names_len = sizeof(surnames) / sizeof(surnames[0]);

	return surnames[sum % names_len];
}

static void usage(const char *argv0)
{
	fprintf(stderr, "Usage: %s first_name last_name gender\n", argv0);
	fprintf(stderr, "  use 'm' or 'f' for gender\n");
}

int main(int argc, char **argv)
{
	char mixed_name[MAX_MIXEDNAME_LEN];
	unsigned char type;
	char in_first_name[256];
	char in_surname[256];
	char in_gender[16];
	const char *first_name;
	const char *surname;

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Find out your elven name and improve your "
			"love life considerably!\n\n");
	printf("What is your first name? ");
	fgets(in_first_name, 256, stdin);
	in_first_name[strlen(in_first_name)-1] = '\0';
	printf("What is your last name? ");
	fgets(in_surname, 256, stdin);
	in_surname[strlen(in_surname)-1] = '\0';
	printf("What is your gender? (m/f) ");
	fgets(in_gender, 16, stdin);
	in_gender[strlen(in_gender)-1] = '\0';

	if (strcmp(in_gender, "m") == 0)
		type = 1;
	else if (strcmp(in_gender, "f") == 0)
		type = 2;
	else {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	mix_names(in_first_name, in_surname, mixed_name, MAX_MIXEDNAME_LEN);
	first_name = get_first_name(mixed_name, MAX_MIXEDNAME_LEN, type);
	surname = get_surname(mixed_name, MAX_MIXEDNAME_LEN, type);

	printf("\nYour elven name is %s %s\n", first_name, surname);

	return 0;
}
