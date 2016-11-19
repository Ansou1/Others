#include			<sstream>
#include			"HomeWindow.hpp"

HomeWindow::HomeWindow() : _name(new QLineEdit),
			   _primClass(new QLineEdit),
			   _directory(new QPushButton("./")),
			   _protect(new QCheckBox("Proteger le header contre les inclusions multiples")),
			   _construct(new QCheckBox("Generer un constructeur par defaut")),
			   _destruct(new QCheckBox("Generer un destructeur")),
			   _autor(new QLineEdit(DEF_NAME)),
			   _project(new QLineEdit(DEF_PROJECT)),
			   _dateTime(new QDateTimeEdit),
			   _todo(new QTextEdit),
			   _generate(new QPushButton("Generer !")),
			   _quit(new QPushButton("Quitter"))
{
  QVBoxLayout*			layoutPrincipal = new QVBoxLayout;
  
  layoutPrincipal->addWidget(setDefinition());
  layoutPrincipal->addWidget(setOptions());
  layoutPrincipal->addWidget(setComments());
  layoutPrincipal->addLayout(setButtons());
  setLayout(layoutPrincipal);
  setWindowTitle("CClass Creator");
  resize(400, 450);

  connect(_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(_generate, SIGNAL(clicked()), this, SLOT(genHpp()));
  connect(_generate, SIGNAL(clicked()), this, SLOT(genCpp()));
}

void				HomeWindow::selectDirectory()
{
  QString			tmp = QFileDialog::getExistingDirectory(this);

  if (!tmp.isEmpty())
    {
      if (tmp.toStdString() != std::string(getenv("PWD")))
	getDirectory()->setText(tmp);
      else
	getDirectory()->setText("./");
    }
}

QGroupBox*			HomeWindow::setDefinition()
{
  QFormLayout*			definitionLayout = new QFormLayout;
  QGroupBox*			groupDefinition = new QGroupBox("Definition de la classe");

  definitionLayout->addRow("Nom :", _name);
  definitionLayout->addRow("Classe mere :", _primClass);
  definitionLayout->addRow("Emplacement :", _directory);
  groupDefinition->setLayout(definitionLayout);

  connect(_directory, SIGNAL(clicked()), this, SLOT(selectDirectory()));

  return (groupDefinition);
}

QGroupBox*			HomeWindow::setOptions()
{
  QVBoxLayout*			optionsLayout = new QVBoxLayout;
  QGroupBox*			groupOptions = new QGroupBox("Options");

  getProtect()->setChecked(true);
  getConstruct()->setChecked(true);
  getDestruct()->setChecked(true);
  optionsLayout->addWidget(_protect);
  optionsLayout->addWidget(_construct);
  optionsLayout->addWidget(_destruct);
  groupOptions->setLayout(optionsLayout);

  return (groupOptions);
}

QGroupBox*			HomeWindow::setComments()
{
  QFormLayout*			commentairesLayout = new QFormLayout;

  getDateTime()->setDate(QDate::currentDate());
  getDateTime()->setTime(QTime::currentTime());
  commentairesLayout->addRow("Auteur :", _autor);
  commentairesLayout->addRow("Projet :", _project);
  commentairesLayout->addRow("To do :", _todo);
  _comments = new QGroupBox("Ajouter un header");
  getComments()->setCheckable(true);
  getComments()->setChecked(true);
  getComments()->setLayout(commentairesLayout);

  return (_comments);
}

QHBoxLayout*			HomeWindow::setButtons()
{
  QHBoxLayout*			boutonsLayout = new QHBoxLayout;

  boutonsLayout->setAlignment(Qt::AlignRight);
  boutonsLayout->addWidget(_generate);
  boutonsLayout->addWidget(_quit);

  return (boutonsLayout);
}

void				HomeWindow::fillComments(QString& code, bool flag)
{
  code += "//\n// " + getName()->text() + ".hpp for " + getProject()->text() + " in " + getenv("PWD")
    + "\n//\n// Made by " + getAutor()->text() + "\n// Login   <" + getenv("USER") + "@epitech.net>\n//\n// Started on  "
    + getDateTime()->dateTime().toString("ddd MMM dd hh:mm:ss yyyy") + " " + getAutor()->text()
    + "\n// Last update " + getDateTime()->dateTime().toString("ddd MMM dd hh:mm:ss yyyy") + " " + getAutor()->text() + "\n//\n\n";
  if (!getTodo()->toPlainText().isEmpty() && flag)
    {
      std::stringstream         tmp(getTodo()->toPlainText().toStdString());
      std::string               line;

      while (getline(tmp, line))
        code += "// todo : " + QString::fromStdString(line) + "\n";
      code += "\n";
    }
}

void				HomeWindow::genNoGraph()
{
  genHpp();
  genCpp();
}
