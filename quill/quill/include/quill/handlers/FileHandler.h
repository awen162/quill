/**
 * Copyright(c) 2020-present, Odysseas Georgoudis & quill contributors.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#pragma once

#include "quill/handlers/StreamHandler.h"
#include <utility>

namespace quill
{

enum class FilenameAppend
{
  Date,
  None
};

/**
 * Creates a new instance of the FileHandler class.
 * The specified file is opened and used as the stream for logging.
 * If mode is not specified, "a" is used.
 * By default, the file grows indefinitely.
 */
class FileHandler : public StreamHandler
{
public:
  /**
   * This constructor will always call fopen to open the given file
   * @param filename
   * @param mode
   */
  FileHandler(filename_t const& filename, std::string const& mode, FilenameAppend append_to_filenae);

  ~FileHandler() override;

protected:
  /**
   * This constructor will not call fopen. It will just store the filename as base_filename and is
   * used by FileHandlers that derive from this class e.g. DailyFileHandler. Those filehandlers
   * usually do not operate directly on the base_filename but instead they usually append
   * something to the filename and open it themselves
   * @param filename
   */
  explicit FileHandler(filename_t const& filename);

protected:
  filename_t _current_filename; /**< Includes the base filename and some additional info e.g. an appended date or an index */
};
} // namespace quill