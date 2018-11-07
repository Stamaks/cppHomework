////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Contains interfaces for the following classes:
///                 JournalNetActivity.
///
/// \author     Leonid W. Dworzanski <leo@mathtech.ru> © 2014–2016.
/// \author     Sergey A. Shershakov <sshershakov@hse.ru> © 2015–2018.
/// \version    2.0.0
/// \date       28.10.2018
///             This is a part of the course "Algorithms and Data Structures"
///             provided by  the School of Software Engineering of the Faculty
///             of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///
////////////////////////////////////////////////////////////////////////////////


#ifndef CYBERPOLICE_JOURNAL_NET_ACTIVITY_H_
#define CYBERPOLICE_JOURNAL_NET_ACTIVITY_H_


#include "skip_list.h"
#include "net_activity.h"
#include "time_stamp.h"


/*! ****************************************************************************
 *  Represents an activities that tracked in an access log.
 ******************************************************************************/
template <int numLevels>
class JournalNetActivity
{
public:
    /// Alias for typed SkipList.
    typedef SkipList<NetActivity, TimeStamp, numLevels> NetActivityList;

public:

    /// Just dumps the whole journal to the \a out stream.
    void dumpJournal(std::ostream& out);

    /// Reads the whole log from the file on \a fullpath.
    void parseLog(const std::string& fullpath);

    /// Outputs all net activity between \a from and \a to.
    void outputSuspiciousActivities(const std::string& site,
        const TimeStamp& from, const TimeStamp& to) const;

protected:
    /// Log storage.
    NetActivityList _journal;
};


// Move out "implementation" to a separate header.
#include "journal_net_activity.hpp"


#endif // CYBERPOLICE_JOURNAL_NET_ACTIVITY_H_
