#ifndef			_HOMEWINDOW_HPP_
# define		_HOMEWINDOW_HPP_

# define		DEF_NAME	"Anthony DURET"
# define		DEF_PROJECT	"EPITECH"

# include		<QtGui>

class			HomeWindow : public QWidget
{
  Q_OBJECT
  
private:
  QLineEdit*		_name;
  QLineEdit*		_primClass;
  QPushButton*		_directory;
  QCheckBox*		_protect;
  QCheckBox*		_construct;
  QCheckBox*		_destruct;
  QGroupBox*		_comments;
  QLineEdit*		_autor;
  QLineEdit*		_project;
  QDateTimeEdit*	_dateTime;
  QTextEdit*		_todo;
  QPushButton*		_generate;
  QPushButton*		_quit;
private slots:
  void			selectDirectory();
  bool			genHpp();
  bool			genCpp();
public:
  HomeWindow();
  QLineEdit*		getName() const {return (_name);}
  QLineEdit*		getPrimClass() const {return (_primClass);}
  QPushButton*		getDirectory() const {return (_directory);}
  QCheckBox*		getProtect() const {return (_protect);}
  QCheckBox*		getConstruct() const {return (_construct);}
  QCheckBox*		getDestruct() const {return (_destruct);}
  QGroupBox*		getComments() const {return (_comments);}
  QLineEdit*		getProject() const {return (_project);}
  QLineEdit*		getAutor() const {return (_autor);}
  QDateTimeEdit*	getDateTime() const {return (_dateTime);}
  QTextEdit*		getTodo() const {return (_todo);}
  QGroupBox*		setDefinition();
  QGroupBox*		setOptions();
  QGroupBox*		setComments();
  QHBoxLayout*		setButtons();
  void			fillComments(QString&, bool = true);
  void			genNoGraph();
};

#endif			/* !_HOMEWINDOW_HPP_ */
