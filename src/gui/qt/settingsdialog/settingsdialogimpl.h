/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2011 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *****************************************************************************/
#ifndef SETTINGSDIALOGIMPL_H
#define SETTINGSDIALOGIMPL_H

#include "ui_settingsdialog.h"
#include "selectavatardialogimpl.h"
#include "manualblindsorderdialogimpl.h"

#include <QtCore>
#include <QtGui>

#include <boost/shared_ptr.hpp>
#include <vector>
#include <iostream>

class ConfigFile;
class selectAvatarDialogImpl;
class manualBlindsOrderDialogImpl;
class MyStyleListItem;
class guiLog;

class settingsDialogImpl: public QDialog, public Ui::settingsDialog
{
	Q_OBJECT
public:
	settingsDialogImpl(QWidget *parent = 0, ConfigFile *c = 0, selectAvatarDialogImpl *s = 0);

	~settingsDialogImpl();

	void prepareDialog();
	void exec(bool ingame);

	void setPlayerNickIsChanged(bool theValue) {
		playerNickIsChanged = theValue;
	}
	bool getPlayerNickIsChanged() const {
		return playerNickIsChanged;
	}

	bool getSettingsCorrect() const {
		return settingsCorrect;
	}

	void setGuiLog(guiLog* l) {
		myGuiLog = l;
	}

public slots:

	void isAccepted();
	void playerNickChanged() {
		setPlayerNickIsChanged(TRUE);
	};
	void setFlipsidePicFileName();
	void setLogDir();
	void setAvatarFile0();
	void setAvatarFile1();
	void setAvatarFile2();
	void setAvatarFile3();
	void setAvatarFile4();
	void setAvatarFile5();
	void setAvatarFile6();
	void setAvatarFile7();
	void setAvatarFile8();
	void setAvatarFile9();

	void callManualBlindsOrderDialog();
	void callNetManualBlindsOrderDialog();

	void callSelectAvatarDialog() {
		mySelectAvatarDialogImpl->exec();
	}

	void clearInternetGamePassword(bool);

// 	void checkProperNetFirstSmallBlind(int);
// 	void checkProperFirstSmallBlind(int);
	void setFirstSmallBlindMargin() ;

	void setLanguageChanged(int);

	void toggleGroupBoxAutomaticServerConfig(bool /*toggleState*/);
	void toggleGroupBoxManualServerConfig(bool /*toggleState*/);

	void setSelectedGameTableStyleActivated();
	void showCurrentGameTableStylePreview();
	void addGameTableStyle();
	void removeGameTableStyle();

	void setSelectedCardDeckStyleActivated();
	void showCurrentCardDeckStylePreview();
	void addCardDeckStyle();
	void removeCardDeckStyle();
	void removePlayerFromIgnoredPlayersList();
	void refreshLogFileList();
	void deleteLogFile();
	void exportLogToHtml();
	void exportLogToTxt();
	void saveLogFileAs();
	void showLogFilePreview();
	void resetSettings();

private:

	bool playerNickIsChanged;
	bool settingsCorrect;

	bool myAfterMBAlwaysDoubleBlinds;
	bool myNetAfterMBAlwaysDoubleBlinds;
	bool myAfterMBAlwaysRaiseAbout;
	bool myNetAfterMBAlwaysRaiseAbout;
	bool myAfterMBStayAtLastBlind;
	bool myNetAfterMBStayAtLastBlind;
	int myAfterMBAlwaysRaiseValue;
	int myNetAfterMBAlwaysRaiseValue;
	std::list<int> myManualBlindsList;
	std::list<int> myNetManualBlindsList;
	std::list<std::string> myGameTableStylesList;
	std::list<std::string> myCardDeckStylesList;

	ConfigFile* myConfig;
	guiLog* myGuiLog;
	selectAvatarDialogImpl *mySelectAvatarDialogImpl;
	manualBlindsOrderDialogImpl *myManualBlindsOrderDialog;

	QString myAppDataPath;

	bool languageIsChanged;
	bool calledIngame;
	int changedLanguageIndex;
};

#endif
