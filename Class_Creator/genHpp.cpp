#include			<fstream>
#include			"HomeWindow.hpp"

static bool			createFile(QString const& name, QString const& path, QString& code)
{
  std::ofstream                 file((path.toStdString() + "/" + name.toStdString() + ".hpp").c_str(), std::ios::out | std::ios::trunc);

  if (!file)
    return (false);
  file << code.toStdString();
  file.close();

  return (true);
}

bool                            HomeWindow::genHpp()
{
  if (getName()->text().isEmpty())
    return (false);

  QString                       code;

  if (getComments()->isChecked())
    fillComments(code);
  if (getProtect()->isChecked())
    code += "#ifndef			_" + getName()->text().toUpper() + "_HPP_\n"
      + "# define		_" + getName()->text().toUpper() + "_HPP_\n\n";
  if (!getPrimClass()->text().isEmpty())
    code += "# include		\"" + getPrimClass()->text() + ".hpp\"\n\n";
  code += "class			" + getName()->text();
  (!getPrimClass()->text().isEmpty())
    ? (code += " : public " + getPrimClass()->text() + "\n{\nprotected:\n")
    : (code += "\n{\nprivate:\n");
  code += "\npublic:\n";
  if (getConstruct()->isChecked())
    code += "  " + getName()->text() + "();\n";
  if (getDestruct()->isChecked())
    code += "  ~" + getName()->text() + "();\n";
  code += "};\n\n";
  if (getProtect()->isChecked())
    code += "#endif			/* !_" + getName()->text().toUpper() + "_HPP_ */\n";

  if (!createFile(getName()->text(), getDirectory()->text(), code))
    return (false);

  return (true);
}
